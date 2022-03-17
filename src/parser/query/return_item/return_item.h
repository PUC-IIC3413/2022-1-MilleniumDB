#pragma once

#include "base/query/var.h"

class ReturnItem {
public:
    virtual ~ReturnItem() = default;

    virtual Var get_var() const = 0;

    virtual std::ostream& print_to_ostream(std::ostream& os, int indent = 0) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const ReturnItem& b) {
        return b.print_to_ostream(os);
    }
};
