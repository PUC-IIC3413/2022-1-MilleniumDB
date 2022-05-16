#pragma once

#include "execution/binding_id_iter/empty_binding_id_iter.h"
#include "query_optimizer/quad_model/plan/plan.h"

class DummyJoinPlan : public Plan {
private:
    std::unique_ptr<Plan> lhs;
    std::unique_ptr<Plan> rhs;

public:
    DummyJoinPlan(std::unique_ptr<Plan> lhs, std::unique_ptr<Plan> rhs) :
        lhs  (std::move(lhs)),
        rhs  (std::move(rhs)) { }

    std::unique_ptr<Plan> duplicate() const override {
        return std::make_unique<DummyJoinPlan>(lhs->duplicate(), rhs->duplicate());
    }

    double estimate_cost() const override {
        return lhs->estimate_output_size() + 3*rhs->estimate_output_size();
    }

    double estimate_output_size() const override {
        uint64_t l_size = lhs->estimate_output_size();
        uint64_t r_size = rhs->estimate_output_size();

        uint64_t magic_number = (l_size >> 1) ^ (r_size << 1);

        return (magic_number * l_size * r_size) % 3145739;
    }

    void print(std::ostream& os, int indent, const std::vector<std::string>& var_names) const override {
        os << '(';
        lhs->print(os, indent, var_names);
        os << ',';
        rhs->print(os, indent, var_names);
        os << ')';
    }

    std::unique_ptr<BindingIdIter> get_binding_id_iter(ThreadInfo*) const override {
        return std::make_unique<EmptyBindingIdIter>();
    }

    std::set<VarId> get_vars() const override { return std::set<VarId>(); }

    void set_input_vars(const std::set<VarId>& /*input_vars*/) override { }

    bool get_leapfrog_iter(ThreadInfo*,
                           std::vector<std::unique_ptr<LeapfrogIter>>&,
                           std::vector<VarId>&,
                           uint_fast32_t&) const override { return false; }
};
