#include <cstdlib>
#include <iostream>
#include <memory>

#include "query_optimizer/quad_model/join_order/bushy_greedy_optimizer.h"
#include "query_optimizer/quad_model/join_order/exhaustive_optimizer.h"
#include "query_optimizer/quad_model/join_order/greedy_optimizer.h"
#include "query_optimizer/quad_model/join_order/selinger_optimizer.h"
#include "query_optimizer/quad_model/plan/basic/dummy_plan.h"


// Test Lab 4
int main() {
    // Random seed
    srand(1);

    // Needed for the interface, but not used in this case
    std::vector<std::string> var_names;

    // Base plans construction
    // ****Example Solution for Bushy Greedy Optimizer: ((B,D),(A,C))****
    // ****Example Solution for Exhaustive Optimizer: (((B,D),A),C)****
    /*
    TODO: Aquí pueden cambiar el ejemplo a evaluar con su optimizador.
    Basta con agregar/remover componentes al vector de abajo, eligiendo siempre un char distinto
    como segundo argumento al constructor de DummyPlan.
    Notar que las soluciones esperadas que salen arriba de este comentario son sólo para el ejemplo default
    que viene con este archivo (con las relaciones A,B,C,D).
    */
    std::vector<std::unique_ptr<Plan>> base_plans;
    base_plans.push_back(std::make_unique<DummyPlan>(rand(), 'A'));
    base_plans.push_back(std::make_unique<DummyPlan>(rand(), 'B'));
    base_plans.push_back(std::make_unique<DummyPlan>(rand(), 'C'));
    base_plans.push_back(std::make_unique<DummyPlan>(rand(), 'D'));

    // Selinger optimizer example
    //SelingerOptimizer optimizer(std::move(base_plans), var_names);
    //auto join_plan = optimizer.get_plan();

    // Greedy optimizer example
    //auto join_plan = GreedyOptimizer::get_plan(std::move(base_plans), var_names);

    // Bushy Greedy optimizer ****(for testing this LAB)****
    auto join_plan = BushyGreedyOptimizer::get_plan(std::move(base_plans), var_names);

    // Exhaustive optimizer ****(for testing the BONUS)****
    //auto join_plan = ExhaustiveOptimizer::get_plan(std::move(base_plans), var_names);

    // Optimized join plan
    join_plan->print(std::cout, 0, var_names);
    std::cout << "\nEstimated cost: " << (uint64_t)join_plan->estimate_cost() << '\n';
    return 0;
}
