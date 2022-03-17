#pragma once

#include <string>
#include <vector>

#include "parser/query/op/op.h"
#include "parser/query/return_item/return_item.h"

class OpGroupBy : public Op {
public:
    std::unique_ptr<Op> op;

    std::vector<std::unique_ptr<ReturnItem>> items;

    OpGroupBy(std::unique_ptr<Op> op,
               std::vector<std::unique_ptr<ReturnItem>>&& items) :
        op    (std::move(op)),
        items (std::move(items)) { }

    void accept_visitor(OpVisitor& visitor) override {
        visitor.visit(*this);
    }

    std::set<Var> get_vars() const override {
        auto res = op->get_vars();
        // TODO: add new vars? (e.g. MATCH (?x :Person) GROUP BY ?x.age)
        // for (const auto& item : items) {
        // }
        return res;
    }

    std::ostream& print_to_ostream(std::ostream& os, int indent = 0) const override {
        os << std::string(indent, ' ');
        os << "OpGroupBy(";
        for (unsigned i = 0; i < items.size(); i++) {
            if (i != 0) {
                os << ", ";
            }
            os << *items[i];
        }
        os << ")\n";
        return op->print_to_ostream(os, indent + 2);
    }
};
