#pragma once

#include <vector>

#include "structures.h"

namespace json {
class Parser final {
public:
    Parser();
    ~Parser();

public:
    bool parse();

private:
    std::vector<User> users;
};

}
