#pragma once

#include "parser/query/return_item/return_item.h"

class ReturnItemCount : public ReturnItem {
public:
    bool distinct;

    Var var;

    ReturnItemCount(bool distinct, Var&& var) :
        distinct (distinct),
        var      (std::move(var)) { }

    Var get_var() const override {
        return var;
    }

    std::ostream& print_to_ostream(std::ostream& os, int indent = 0) const override {
        return os << std::string(' ', indent) << "COUNT" << '(' << (distinct ? "DISTINCT " : "") << var << ')';
    }
};