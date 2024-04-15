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
    std::vector<std::string> &parse(std::ifstream &file);

private:
    std::regex _pattern;
    std::vector<std::string> _objects;
    //TODO std::vector<User> _users;
};

}
