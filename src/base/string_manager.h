#pragma once

#include <string>

class StringManager {
public:
    static StringManager* instance;

    virtual ~StringManager() = default;

    virtual std::string get_string(uint64_t string_id) const = 0;
};
