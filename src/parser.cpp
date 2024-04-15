#include "parser.h"

#include <iostream>

namespace json {
    void Parser::setPattern(const std::string &pattern) {
        _pattern = pattern;
    }

    std::vector<std::string> &Parser::parse(std::ifstream &file) {
        std::string line;
        while (std::getline(file, line)) {
            std::sregex_iterator it(line.begin(), line.end(), _pattern);
            std::sregex_iterator it_end;
            for (; it != it_end; ++it) {
                std::cout << it->str() << std::endl;
                _objects.push_back(it->str());
            }
        }
        return _objects;
    }
}
