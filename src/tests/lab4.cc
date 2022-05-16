#include <cstdlib>
#include <iostream>
#include <memory>

#include "query_optimizer/quad_model/join_order/greedy_optimizer.h"
#include "query_optimizer/quad_model/join_order/selinger_optimizer.h"
#include "query_optimizer/quad_model/plan/basic/dummy_plan.h"

int main() {
    srand(1);

    std::vector<std::unique_ptr<Plan>> base_plans;
    base_plans.push_back(std::make_unique<DummyPlan>(rand(), 'A'));
    base_plans.push_back(std::make_unique<DummyPlan>(rand(), 'B'));
    base_plans.push_back(std::make_unique<DummyPlan>(rand(), 'C'));
    base_plans.push_back(std::make_unique<DummyPlan>(rand(), 'D'));

    std::vector<std::string> var_names; // needed for the interface, but not used in this case

    SelingerOptimizer optimizer(std::move(base_plans), var_names);
    auto join_plan = optimizer.get_plan();

    // Pueden comentar las 2 lineas de arriba y descomentar la de abajo para usar el GreedyOptimizer en lugar del SelingerOptimizer
    // auto join_plan = GreedyOptimizer::get_plan(std::move(base_plans), var_names);

    join_plan->print(std::cout, 0, var_names);
    std::cout << "\nEstimated cost: " << (uint64_t)join_plan->estimate_cost() << '\n';

    return 0;
}