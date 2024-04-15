#include "parser.h"

#include <iostream>

namespace json {
    void Parser::setPattern(const std::string &pattern) {
        _pattern = pattern;
    }

    void Parser::getUser(const std::string &string) {
        const std::regex pattern("\"UserID\":(\\d+),\"UserName\":\"([^\"]+)\",\"UserSurname\":\"([^\"]+)\",\"RegistrationDate\":\"([^\"]+)\",\"Password\":\"([^\"]+)\"");
        std::smatch matches;
        if (std::regex_search(string, matches, pattern)) {
            json::structures::User user;
            user.UserID = std::stoi(matches[1]);
            user.UserName = matches[2];
            user.UserSurname = matches[3];
            user.RegistrationDate = matches[4];
            user.Password =  matches[5];
            _users.push_back(user);
        } else {
            throw "Не удалось разбрать на компоненты";
        }
    }

    std::vector<structures::User> &Parser::parse(std::ifstream &file) {
        std::string line;
        while (std::getline(file, line)) {
            std::sregex_iterator it(line.begin(), line.end(), _pattern);
            std::sregex_iterator it_end;
            for (; it != it_end; ++it) {
                getUser(it->str());
            }
        }
        return _users;
    }
}
