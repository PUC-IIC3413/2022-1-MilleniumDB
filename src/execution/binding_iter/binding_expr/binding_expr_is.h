#pragma once

#include <memory>

#include "parser/query/expr/bool_expr/expr_comaprision/expr_is.h"
#include "execution/binding_iter/binding_expr/binding_expr.h"

class BindingExprIs : public BindingExpr {
public:
    std::unique_ptr<BindingExpr> expr;

    bool negation;

    ExprTypeName type;

    BindingExprIs(std::unique_ptr<BindingExpr> expr, bool negation, ExprTypeName type) :
        expr     (std::move(expr)),
        negation (negation),
        type     (type) { }

    GraphObject eval(const BindingIter& binding_iter) const override {
        auto eval = expr->eval(binding_iter);
        // using GraphObjectVariant = std::variant<NullGraphObject, NotFoundObject, IdentifiableInlined, IdentifiableExternal,
        //                                 Edge, AnonymousNode, Path, bool, StringInlined, StringExternal, int64_t, float>;
        switch (type) {
            case ExprTypeName::NULL_:
                if (std::holds_alternative<NullGraphObject>(eval.value)) {
                    return GraphObject::make_bool(true ^ negation);
                } else {
                    return GraphObject::make_bool(false ^ negation);
                }

            case ExprTypeName::INTEGER:
                if (std::holds_alternative<int64_t>(eval.value)) {
                    return GraphObject::make_bool(true ^ negation);
                } else {
                    return GraphObject::make_bool(false ^ negation);
                }

            case ExprTypeName::FLOAT:
                if (std::holds_alternative<float>(eval.value)) {
                    return GraphObject::make_bool(true ^ negation);
                } else {
                    return GraphObject::make_bool(false ^ negation);
                }

            case ExprTypeName::BOOL:
                if (std::holds_alternative<bool>(eval.value)) {
                    return GraphObject::make_bool(true ^ negation);
                } else {
                    return GraphObject::make_bool(false ^ negation);
                }

            case ExprTypeName::STRING:
                if (std::holds_alternative<StringInlined>(eval.value)
                    || std::holds_alternative<StringExternal>(eval.value))
                {
                    return GraphObject::make_bool(true ^ negation);
                } else {
                    return GraphObject::make_bool(false ^ negation);
                }
        }
        return GraphObject::make_bool(false ^ negation);
    }
};
