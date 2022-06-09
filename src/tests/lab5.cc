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

    /*
    x <- 0
    y <- 1
    z <- 2
    u <- 3
    v <- 4
    w <- 5
    t <- 6
    */

    R.insert(VarId(0));
    R.insert(VarId(1));
    R.insert(VarId(2));

    S.insert(VarId(0));
    S.insert(VarId(1));
    S.insert(VarId(3));


    T.insert(VarId(0));
    T.insert(VarId(4));
    T.insert(VarId(5));

    U.insert(VarId(7));
    U.insert(VarId(8));
    U.insert(VarId(9));


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
