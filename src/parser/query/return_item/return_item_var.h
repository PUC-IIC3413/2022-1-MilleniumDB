#pragma once

#include "parser/query/return_item/return_item.h"

class ReturnItemVar : public ReturnItem {
public:
    Var var;

    ReturnItemVar(const Var& var) :
        var (var) { }

    ReturnItemVar(Var&& var) :
        var (std::move(var)) { }

    Var get_var() const override {
        return var;
    }

    std::ostream& print_to_ostream(std::ostream& os, int indent = 0) const override {
        return os << std::string(' ', indent) << var;
    }
};