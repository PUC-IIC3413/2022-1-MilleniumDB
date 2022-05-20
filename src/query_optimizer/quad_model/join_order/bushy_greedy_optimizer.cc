#include "bushy_greedy_optimizer.h"

#include <iostream>
#include <limits>

#include "query_optimizer/quad_model/plan/join/dummy_join_plan.h"

using namespace std;

unique_ptr<Plan> BushyGreedyOptimizer::get_plan(vector<unique_ptr<Plan>> base_plans,
                                                const vector<string>& var_names)
{
    // Need to have at least one relation
    const auto base_plans_size = base_plans.size();
    assert(base_plans_size > 0);

    /*
    TODO: Aquí deben implementar el método Greedy para planes Bushy.
    Lo de abajo es sólo un ejemplo visto en la ayudantía que genera el orden de los joins secuencialmente.
    */

    // Trivial join selection in sequence
    auto join_plan = base_plans[0]->duplicate();
    for (size_t i = 1; i < base_plans_size; i++) {
        auto new_plan = make_unique<DummyJoinPlan>(join_plan->duplicate(), base_plans[i]->duplicate());
        join_plan = move(new_plan);
    }

    return join_plan;
}
