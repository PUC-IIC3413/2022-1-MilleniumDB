#include "binding_iter_visitor.h"

#include "parser/query/expr/expr_to_binding_condition.h"
#include "execution/binding_id_iter/distinct_id_hash.h"
#include "execution/binding_id_iter/index_scan.h"
#include "execution/binding_id_iter/optional_node.h"
#include "execution/binding_id_iter/paths/path_manager.h"
#include "execution/binding_id_iter/scan_ranges/assigned_var.h"
#include "execution/binding_id_iter/scan_ranges/scan_range.h"
#include "execution/binding_id_iter/scan_ranges/term.h"
#include "execution/binding_id_iter/scan_ranges/unassigned_var.h"
#include "execution/binding_iter/describe.h"
#include "execution/binding_iter/match.h"
#include "execution/binding_iter/order_by.h"
#include "execution/binding_iter/return.h"
#include "execution/binding_iter/where.h"
#include "execution/binding_iter/distinct_ordered.h"
#include "execution/binding_iter/distinct_hash.h"
#include "query_optimizer/quad_model/binding_id_iter_visitor.h"
#include "query_optimizer/quad_model/quad_model.h"

using namespace std;

BindingIterVisitor::BindingIterVisitor(std::set<Var> vars, ThreadInfo* thread_info) :
    var2var_id  (construct_var2var_id(vars)),
    thread_info (thread_info) { }


map<Var, VarId> BindingIterVisitor::construct_var2var_id(std::set<Var>& vars) {
    map<Var, VarId> res;
    uint_fast32_t i = 0;
    for (auto& var : vars) {
        res.insert({ var, VarId(i++) });
    }
    return res;
}


VarId BindingIterVisitor::get_var_id(const Var& var) const {
    auto search = var2var_id.find(var);
    if (search != var2var_id.end()) {
        return (*search).second;
    } else {
        throw LogicException("var " + var.name + " not present in var2var_id");
    }
}


void BindingIterVisitor::visit(OpDescribe& op_describe) {
    unique_ptr<BindingIdIter> labels;
    unique_ptr<BindingIdIter> properties;
    unique_ptr<BindingIdIter> outgoing_connections;
    unique_ptr<BindingIdIter> incoming_conenctions;

    QueryElementToGraphObject visitor;
    auto graph_obj = std::visit(visitor, op_describe.node.value);

    ObjectId object_id = quad_model.get_object_id(graph_obj);

    VarId label_var(0);
    VarId key_var(0);
    VarId value_var(1);
    VarId from_var(0);
    VarId to_var(0);
    VarId type_var(1);
    VarId edge_var(2);

    {
        array<unique_ptr<ScanRange>, 2> ranges;
        ranges[0] = make_unique<Term>(object_id);
        ranges[1] = make_unique<UnassignedVar>(label_var);
        labels = make_unique<IndexScan<2>>(*quad_model.node_label,
                                           thread_info,
                                           move(ranges));
    }

    {
        array<unique_ptr<ScanRange>, 3> ranges;
        ranges[0] = make_unique<Term>(object_id);
        ranges[1] = make_unique<UnassignedVar>(key_var);
        ranges[2] = make_unique<UnassignedVar>(value_var);
        properties = make_unique<IndexScan<3>>(*quad_model.object_key_value,
                                               thread_info,
                                               move(ranges));
    }

    {
        array<unique_ptr<ScanRange>, 4> ranges;
        ranges[0] = make_unique<Term>(object_id);
        ranges[1] = make_unique<UnassignedVar>(to_var);
        ranges[2] = make_unique<UnassignedVar>(type_var);
        ranges[3] = make_unique<UnassignedVar>(edge_var);
        outgoing_connections = make_unique<IndexScan<4>>(*quad_model.from_to_type_edge,
                                                          thread_info,
                                                          move(ranges));
    }

    {
        array<unique_ptr<ScanRange>, 4> ranges;
        ranges[0] = make_unique<Term>(object_id);
        ranges[1] = make_unique<UnassignedVar>(type_var);
        ranges[2] = make_unique<UnassignedVar>(from_var);
        ranges[3] = make_unique<UnassignedVar>(edge_var);
        incoming_conenctions = make_unique<IndexScan<4>>(*quad_model.to_type_from_edge,
                                                         thread_info,
                                                         move(ranges));
    }

    tmp = make_unique<Describe>(move(labels),
                                move(properties),
                                move(outgoing_connections),
                                move(incoming_conenctions));
}



void BindingIterVisitor::visit(OpReturn& op_return) {
    // need to save the return items to be able to push optional properties from select to match in visit(OpMatch&)
    for (const auto& return_item : op_return.return_items) {
        string var_str = return_item->get_var().name;

        auto pos = var_str.find('.');
        if (pos != string::npos) {
            // we split something like "?x1.key1" into "?x" and "key1"
            auto var_without_property = var_str.substr(0, pos);
            auto var_key              = var_str.substr(pos + 1);
            var_properties.insert({ Var(var_without_property), var_key });
        }

        Var var(var_str);
        auto var_id = get_var_id(var);
        projection_vars.push_back(make_pair(var, var_id));
    }

    distinct_into_id = op_return.distinct; // OpWhere may change this value when accepting visitor

    op_return.op->accept_visitor(*this);

    if (op_return.distinct) {
        std::vector<VarId> projected_var_ids;
        for (const auto& [var, var_id] : projection_vars) {
            projected_var_ids.push_back(var_id);
        }
        if (distinct_ordered_possible) {
            tmp = make_unique<DistinctOrdered>(move(tmp), move(projected_var_ids));
        } else {
            if (!distinct_into_id) {
                tmp = make_unique<DistinctHash>(move(tmp), move(projected_var_ids));
            }
            // else DistinctIdHash was created when visiting OpMatch
        }
    }

    tmp = make_unique<Return>(move(tmp), move(projection_vars), op_return.limit);
}


void BindingIterVisitor::visit(OpWhere& op_where) {
    distinct_into_id = false;

    // add corresponding var_properties
    for (auto& var : op_where.expr->get_vars()) {
        auto pos = var.name.find('.');
        if (pos != string::npos) {
            // we split something like "?x1.key1" into "?x" and "key1"
            auto var_without_property = var.name.substr(0, pos);
            auto var_key              = var.name.substr(pos + 1);
            var_properties.insert({ Var(var_without_property), var_key });
        }
    }

    // TODO: push negation inside

    // This visitor separates what comes in the Where and what goes into the join
    Expr2BindingExpr expr2binding_expr(var2var_id);
    op_where.expr->accept_visitor(expr2binding_expr);

    auto binding_expr = std::move(expr2binding_expr.current_binding_expr);
    fixed_vars        = std::move(expr2binding_expr.equalities);
    where_properties  = std::move(expr2binding_expr.properties);

    op_where.op->accept_visitor(*this);

    if (binding_expr != nullptr) {
        tmp = make_unique<Where>(move(tmp), move(binding_expr));
    }
}


void BindingIterVisitor::visit(OpMatch& op_match) {
    BindingIdIterVisitor id_visitor(thread_info, var2var_id, fixed_vars);
    op_match.op->accept_visitor(id_visitor);

    unique_ptr<BindingIdIter> binding_id_iter_current_root = move(id_visitor.tmp);

    const auto binding_size = var2var_id.size();

    // TODO: set need_materialize_paths where needed
    path_manager.begin(binding_size, need_materialize_paths);

    vector<unique_ptr<BindingIdIter>> optional_children;

    // Push properties from Select/Where/OrderBy into MATCH as optional children
    for (const auto& [var, prop_name] : var_properties) {
        auto obj_var_id = get_var_id(var);
        auto value_var  = get_var_id(Var(var.name + '.' + prop_name));
        auto key_id     = quad_model.get_object_id(GraphObject::make_string(prop_name));

        // Check value_var does not have a constant value
        if (fixed_vars.find(value_var) == fixed_vars.end()) {
            array<unique_ptr<ScanRange>, 3> ranges {
                ScanRange::get(obj_var_id, true),
                ScanRange::get(key_id, true),
                ScanRange::get(value_var, false)
            };
            auto index_scan = make_unique<IndexScan<3>>(*quad_model.object_key_value, thread_info, move(ranges));
            optional_children.push_back(move(index_scan));
        }
    }
    if (optional_children.size() > 0) {
        binding_id_iter_current_root = make_unique<OptionalNode>(move(binding_id_iter_current_root),
                                                                 move(optional_children));
    }
    if (distinct_into_id) {
        std::vector<VarId> projected_var_ids;
        for (const auto& [var, var_id] : projection_vars) {
            projected_var_ids.push_back(var_id);
        }

        binding_id_iter_current_root = make_unique<DistinctIdHash>(move(binding_id_iter_current_root), move(projected_var_ids));
    }

    tmp = make_unique<Match>(move(binding_id_iter_current_root), binding_size, fixed_vars);
}


void BindingIterVisitor::visit(OpOrderBy& op_order_by) {
    std::vector<VarId> order_vars;
    std::set<VarId> saved_vars;

    for (auto& order_item : op_order_by.items) {
        auto var = order_item->get_var();

        auto pos = var.name.find('.');
        if (pos != string::npos) {
            // we split something like "?x1.key1" into "?x" and "key1"
            auto var_without_property = var.name.substr(0, pos);
            auto var_key              = var.name.substr(pos + 1);
            var_properties.insert({ Var(var_without_property), var_key });
        }
        const auto var_id = get_var_id(var);
        order_vars.push_back(var_id);
        saved_vars.insert(var_id);
    }

    for (auto& [var, var_id] : projection_vars) {
        saved_vars.insert(var_id);
    }

    // TODO: we could set distinct_ordered_possible=true if the projection vars are in the begining
    // e.g. if we have ORDER BY ?x, ?z, ?y RETURN DISTINCT ?x, ?y we can't use DistinctOrdered

    op_order_by.op->accept_visitor(*this);
    tmp = make_unique<OrderBy>(thread_info, move(tmp), saved_vars, order_vars, op_order_by.ascending_order);
}


void BindingIterVisitor::visit(OpGroupBy& op_group_by) {
    // TODO: implement this when GroupBy are supported
    op_group_by.op->accept_visitor(*this);
}
