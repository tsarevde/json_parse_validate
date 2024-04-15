#pragma once

#include <vector>
#include <regex>
#include <fstream>

#include "structures.h"

namespace json {
class Parser final {
public:
    explicit Parser() = default;
    ~Parser() = default;
    Parser(const Parser &) = delete;
    Parser operator=(const Parser &) = delete;

public:
    void setPattern(const std::string &pattern);
    std::vector<User> &parse(std::ifstream &file);
    void getUser(const std::string &string);

private:
    std::regex _pattern;
    std::vector<User> _users;
};

}
