#include "exhaustive_optimizer.h"

#include <iostream>
#include <limits>

#include "query_optimizer/quad_model/plan/join/dummy_join_plan.h"

using namespace std;

unique_ptr<Plan> ExhaustiveOptimizer::get_plan(vector<unique_ptr<Plan>> base_plans,
                                                const vector<string>& var_names)
{
    // Need to have at least one relation
    const auto base_plans_size = base_plans.size();
    assert(base_plans_size > 0);

    // TODO: Work here for the BONUS
    return move(base_plans[0]);
}
