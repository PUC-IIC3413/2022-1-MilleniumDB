#include <cstdlib>
#include <iostream>
#include <memory>
#include <set>

#include "query_optimizer/quad_model/join_order/selinger_optimizer.h"
#include "query_optimizer/quad_model/plan/basic/relation_plan.h"

// Test Lab 5
int main() {
    std::set<VarId> R;
    std::set<VarId> S;
    std::set<VarId> T;
    std::set<VarId> U;

    auto x = VarId(0);
    auto y = VarId(1);
    auto z = VarId(2);
    auto u = VarId(3);
    auto v = VarId(4);
    auto w = VarId(5);
    auto t = VarId(6);

    R.insert(x);
    R.insert(y);
    R.insert(z);

    S.insert(x);
    S.insert(y);
    S.insert(u);

    T.insert(x);
    T.insert(v);
    T.insert(w);

    U.insert(x);
    U.insert(v);
    U.insert(t);

    std::vector<std::unique_ptr<Plan>> base_plans;
    base_plans.push_back(std::make_unique<RelationPlan>(R));
    base_plans.push_back(std::make_unique<RelationPlan>(S));
    base_plans.push_back(std::make_unique<RelationPlan>(T));
    base_plans.push_back(std::make_unique<RelationPlan>(U));

    std::cout << "¿es acíclica? " << SelingerOptimizer::isAcyclic(base_plans) << "\n";
    // Bonus
    SelingerOptimizer::printJoinTree(base_plans);

    return 0;
}
