#pragma once

#include <map>
#include <memory>
#include <vector>

#include <boost/optional.hpp>
#include <boost/variant.hpp>
#include <boost/variant/multivisitors.hpp>

#include "base/query/query_element.h"
#include "base/ids/object_id.h"
#include "base/query/var.h"
#include "parser/query/expr/expr_visitor.h"
#include "execution/binding_iter/binding_expr/binding_expr.h" // TODO: esto tal vez me indica que deberia mover esta clase

// This visitor returns nullptr if condition is pushed outside
class Expr2BindingExpr : public ExprVisitor {
public:
    const std::map<Var, VarId>& var2var_ids;

    std::unique_ptr<BindingExpr> current_binding_expr;

    std::map<VarId, ObjectId> equalities;

    std::vector<std::tuple<Var, std::string, QueryElement>> properties;

    // TODO: make push of properties and negation

    Expr2BindingExpr(const std::map<Var, VarId>& var2var_ids);

    void visit(ExprAtom&) override;
    void visit(ExprAddition&) override;
    void visit(ExprDivision&) override;
    void visit(ExprModulo&) override;
    void visit(ExprMultiplication&) override;
    void visit(ExprSubtraction&) override;
    void visit(ExprUnaryMinus&) override;
    void visit(ExprUnaryPlus&) override;
    void visit(ExprEquals&) override;
    void visit(ExprGreaterOrEquals&) override;
    void visit(ExprGreater&) override;
    void visit(ExprIs&) override;
    void visit(ExprLessOrEquals&) override;
    void visit(ExprLess&) override;
    void visit(ExprNotEquals&) override;
    void visit(ExprAnd&) override;
    void visit(ExprNot&) override;
    void visit(ExprOr&) override;
};
