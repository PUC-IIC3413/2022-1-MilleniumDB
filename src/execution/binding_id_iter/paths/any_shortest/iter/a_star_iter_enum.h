#pragma once

#include <array>
#include <memory>
#include <queue>
#include <variant>

#include "base/binding/binding_id_iter.h"
#include "base/thread/thread_info.h"
#include "parser/query/paths/path_automaton.h"
#include "execution/binding_id_iter/paths/any_shortest/search_state.h"
#include "execution/binding_id_iter/scan_ranges/scan_range.h"
#include "storage/index/bplus_tree/bplus_tree.h"
#include "third_party/robin_hood/robin_hood.h"

namespace Paths { namespace AnyShortest {

struct PriorityIterState {
    uint32_t state;
    ObjectId object_id;
    // Distance to automaton's final state
    uint32_t distance;
    uint32_t transition = 0;
    std::unique_ptr<BptIter<4>> iter = nullptr;

    PriorityIterState(uint32_t state, ObjectId object_id, uint32_t distance_to_end) :
        state       (state),
        object_id   (object_id),
        distance    (distance_to_end) { }


    // < operator defines the priority of a state. If a > b then a
    // has more priority and will be extracted first in the open
    bool operator<(const PriorityIterState& rhs) const noexcept {
        if (distance == rhs.distance) {
            if (iter != nullptr && rhs.iter == nullptr) {
                return false;
            } return true;
        }
        // If distance > rhs.distance then rhs > this state or
        // another way rhs has more priority because is more near
        // of final state than `this state`
        return distance > rhs.distance;
    }
};

/*
AStarIterEnum uses as heuristic to extract the nearest automaton state to final
state. The paths returned are optimal thanks to AStar optimal property.
*/
class AStarIterEnum : public BindingIdIter {
private:
    // Attributes determined in the constuctor
    ThreadInfo*   thread_info;
    BPlusTree<1>& nodes;
    BPlusTree<4>& type_from_to_edge; // Used to search foward
    BPlusTree<4>& to_type_from_edge; // Used to search backward
    VarId         path_var;
    Id            start;
    VarId         end;
    PathAutomaton automaton;

    // Attributes determined in begin
    BindingId* parent_binding;
    bool is_first = false; // allows next() method to know if it is the first call

    // Ranges to search in BPT. They are not local variables because some positions are reused.
    std::array<uint64_t, 4> min_ids;
    std::array<uint64_t, 4> max_ids;

    // Structs for BFS
    robin_hood::unordered_set<SearchState, SearchStateHasher> visited;
    std::priority_queue<PriorityIterState> open;

    // Statistics
    uint_fast32_t results_found = 0;
    uint_fast32_t bpt_searches = 0;

    robin_hood::unordered_set<SearchState, SearchStateHasher>::iterator current_state_has_next();

    // Set iter attribute for state of the top of priority queue. The state
    // will be removed and replaced by another with the correct iter and the same
    // priority
    void set_iter();

public:
    AStarIterEnum(ThreadInfo*   thread_info,
                  BPlusTree<1>& nodes,
                  BPlusTree<4>& type_from_to_edge,
                  BPlusTree<4>& to_type_from_edge,
                  VarId         path_var,
                  Id            start,
                  VarId         end,
                  PathAutomaton automaton);

    void analyze(std::ostream& os, int indent = 0) const override;
    void begin(BindingId& parent_binding) override;
    void reset() override;
    void assign_nulls() override;
    bool next() override;
};
}} // namespace Paths::AnyShortest
