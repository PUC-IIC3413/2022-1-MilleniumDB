#include "check_var_names.h"

#include "base/exceptions.h"
#include "parser/query/op/ops.h"
#include "parser/query/expr/exprs.h"

void CheckVarNames::visit(OpReturn& op_return) {
    op_return.op->accept_visitor(*this);

    for (auto& return_item : op_return.return_items) {
        Var var = return_item->get_var();
        auto pos = var.name.find('.');
        if (pos != std::string::npos) {
            // var is like "?x.key1" transform into "?x"
            Var var_without_property(var.name.substr(0, pos));
            if (declared_vars.find(var_without_property) == declared_vars.end()) {
                throw QuerySemanticException("Variable \"" + var_without_property.name
                                             + "\" used in RETURN (property) is not declared in MATCH");
            } else if (declared_path_vars.find(var_without_property) != declared_path_vars.end()) {
                throw QuerySemanticException("Variable \"" + var_without_property.name
                                             + "\" is a path and cannot have properties");
            }
        } else {
            // var is like "?x"
            if (declared_vars.find(var) == declared_vars.end()) {
                throw QuerySemanticException("Variable \"" + var.name + "\" used in RETURN is not declared in MATCH");
            }
        }
        if (op_return.distinct) {
            if (declared_path_vars.find(var) != declared_path_vars.end()) {
                throw QuerySemanticException("DISTINCT of path variable \"" + var.name
                                             + "\" is not supported yet");
            }
        }
    }

}


void CheckVarNames::visit(OpOptional& op_optional) {
    op_optional.op->accept_visitor(*this);
    for (auto& optional_child : op_optional.optionals) {
        optional_child->accept_visitor(*this);
    }
}


void CheckVarNames::visit(OpBasicGraphPattern& op_basic_graph_pattern) {
    auto insert_vars = [&](const std::set<Var>& vars) {
        for (auto& var : vars) {
            declared_vars.insert(var);
            if (declared_path_vars.find(var) != declared_path_vars.end()) {
                throw QuerySemanticException("Duplicated path variable \"" + var.name
                                            + "\". Paths must have an unique variable");
            }
        }
    };

    for (auto& label : op_basic_graph_pattern.labels) {
        insert_vars(label.get_vars());
    }
    for (auto& property : op_basic_graph_pattern.properties) {
        insert_vars(property.get_vars());
    }
    for (auto& edge : op_basic_graph_pattern.edges) {
        insert_vars(edge.get_vars());
    }
    for (auto& isolated_var : op_basic_graph_pattern.isolated_vars) {
        insert_vars(isolated_var.get_vars());
    }

    for (auto& path : op_basic_graph_pattern.paths) {
        if (path.from.is_var()) {
            auto var = path.from.to_var();
            declared_vars.insert(var);
            if (declared_path_vars.find(var) != declared_path_vars.end()) {
                throw QuerySemanticException("Duplicated path variable \"" + var.name
                                            + "\". Paths must have an unique variable");
            }
        }

        if (path.to.is_var()) {
            auto var = path.to.to_var();
            declared_vars.insert(var);
            if (declared_path_vars.find(var) != declared_path_vars.end()) {
                throw QuerySemanticException("Duplicated path variable \"" + var.name
                                            + "\". Paths must have an unique variable");
            }
        }

        if (!declared_path_vars.insert(path.var).second) {
            throw QuerySemanticException("Duplicated path variable \"" + path.var.name
                                         + "\". Paths must have an unique variable");
        }
        if (!declared_vars.insert(path.var).second) {
            throw QuerySemanticException("Duplicated path variable \"" + path.var.name
                                         + "\". Paths must have an unique variable");
        }
    }
}


void CheckVarNames::visit(OpWhere& op_where) {
    op_where.op->accept_visitor(*this);
    CheckVarNamesExpr expr_visitor(declared_vars, declared_path_vars);
    op_where.expr->accept_visitor(expr_visitor);
}


void CheckVarNames::visit(OpGroupBy& op_group_by) {
    // TODO: implement when GroupBy is ready
    op_group_by.op->accept_visitor(*this);
}

void CheckVarNames::visit(OpOrderBy& op_order_by) {
    op_order_by.op->accept_visitor(*this);

    for (auto& item : op_order_by.items) {
        Var var = item->get_var();
        auto pos = var.name.find('.');
        if (pos != std::string::npos) {
            // var is like "?x.key1" transform into "?x"
            Var var_without_property(var.name.substr(0, pos));
            if (declared_vars.find(var_without_property) == declared_vars.end()) {
                throw QuerySemanticException("Variable \"" + var_without_property.name
                                             + "\" used in ORDER BY (property) is not declared in MATCH");
            } else if (declared_path_vars.find(var_without_property) != declared_path_vars.end()) {
                throw QuerySemanticException("Variable \"" + var_without_property.name
                                             + "\" is a path and cannot have properties");
            }
        } else {
            // var is like "?x"
            if (declared_vars.find(var) == declared_vars.end()) {
                throw QuerySemanticException("Variable \"" + var.name + "\" used in ORDER BY is not declared in MATCH");
            }
        }
    }
}


void CheckVarNames::visit(OpMatch& op_match) {
    op_match.op->accept_visitor(*this);
}


/*************************** ExprVisitor ***************************/
void CheckVarNamesExpr::visit(ExprAtom& expr) {
    if (expr.atom[0] == '?') {
        auto pos = expr.atom.find('.');
        if (pos != std::string::npos) {
            // var is like "?x.key1" transform into "?x"
            auto var_without_property = expr.atom.substr(0, pos);
            // auto var_key              = expr.atom.substr(pos + 1);
            Var var(var_without_property);
            if (declared_vars.find(var) == declared_vars.end()) {
                throw QuerySemanticException("Variable \"" + var_without_property
                                             + "\" used in WHERE is not declared in MATCH");
            } else if (declared_path_vars.find(var) != declared_path_vars.end()) {
                throw QuerySemanticException("Variable \"" + var_without_property
                                             + "\" is a path and cannot have properties");
            }
        } else {
            // var is like "?x"
            Var var(expr.atom);
            if (declared_vars.find(var) == declared_vars.end()) {
                throw QuerySemanticException("Variable \"" + expr.atom + "\" used in WHERE is not declared in MATCH");
            }
        }
    }
}


void CheckVarNamesExpr::visit(ExprAddition& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprDivision& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprModulo& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprMultiplication& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprSubtraction& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprEquals& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprGreaterOrEquals& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprGreater& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprLessOrEquals& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprLess& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprNotEquals& expr) {
    expr.lhs->accept_visitor(*this);
    expr.rhs->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprUnaryMinus& expr) {
    expr.expr->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprUnaryPlus& expr) {
    expr.expr->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprNot& expr) {
    expr.expr->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprIs& expr) {
    expr.expr->accept_visitor(*this);
}


void CheckVarNamesExpr::visit(ExprAnd& expr) {
    for (auto& e : expr.and_list) {
        e->accept_visitor(*this);
    }
}


void CheckVarNamesExpr::visit(ExprOr& expr) {
    for (auto& e : expr.or_list) {
        e->accept_visitor(*this);
    }
}
