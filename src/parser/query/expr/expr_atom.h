#pragma once

#include "parser/query/expr/expr.h"

class ExprAtom : public Expr {
public:
    // may be a var or a value (int and float won't have sign).
    // e.g: ?x, ?x.key, true, false, "string", 123, 0.12
    std::string atom;

    ExprAtom(const std::string& atom) :
        atom (atom) { }

    ExprAtom(std::string&& atom) :
        atom (std::move(atom)) { }

    void accept_visitor(ExprVisitor& visitor) override {
        visitor.visit(*this);
    }

    std::set<Var> get_vars() const override {
        std::set<Var> res;
        if (atom[0] == '?') {
            res.emplace(atom);
        }
        return res;
    }

    std::ostream& print_to_ostream(std::ostream& os, int indent = 0) const override {
        return os << std::string(' ', indent) << atom;
    }
};