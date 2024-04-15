#include "parser.h"

#include <iostream>

namespace json {
    Parser::Parser() {
        std::cout << "parser" << std::endl;
    }

    Parser::~Parser() {
        std::cout << "parser delete" << std::endl;
    }


    bool Parser::parse() {
        const std::string json_pattern =
                R"(\[\{"UserID":[0-9]{1,64},
                "UserName":".{1,64}",
                "UserSurname":".{1,64}",
                "RegistrationDate":".{1,32}",
                "Password":".{1,128}"\}\])";
        return false;
    }
}