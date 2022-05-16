#pragma once

#include "execution/binding_id_iter/empty_binding_id_iter.h"
#include "query_optimizer/quad_model/plan/plan.h"

class DummyPlan : public Plan {
private:
    uint64_t seed;
    char name;

public:
    DummyPlan(uint64_t seed, char name) :
        seed (seed),
        name (name) { }

    std::unique_ptr<Plan> duplicate() const override {
        return std::make_unique<DummyPlan>(seed, name);
    }

    double estimate_cost() const override {
        return estimate_output_size();
    }

    double estimate_output_size() const override {
        return seed % 10000;
    }

    std::unique_ptr<BindingIdIter> get_binding_id_iter(ThreadInfo*) const override {
        return std::make_unique<EmptyBindingIdIter>();
    }

    void print(std::ostream& os, int /*indent*/, const std::vector<std::string>& /*var_names*/) const override {
        os << name;
    }

    bool get_leapfrog_iter(ThreadInfo*,
                           std::vector<std::unique_ptr<LeapfrogIter>>&,
                           std::vector<VarId>&,
                           uint_fast32_t&) const override { return false; }

    std::set<VarId> get_vars() const override { return std::set<VarId>(); }
    void set_input_vars(const std::set<VarId>& /*input_vars*/) { }
};
