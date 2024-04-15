#pragma once
#include <string>

namespace json {
    struct User {
        int UserID;
        std::string UserName;
        std::string UserSurname;
        std::string RegistrationDate;
        std::string Password;
    };
}