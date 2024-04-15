#pragma once
#include <string>

namespace json::structures {
    struct User final {
        int UserID;                     // Идентификатор
        std::string UserName;           // Имя
        std::string UserSurname;        // Фамилия
        std::string RegistrationDate;   // Дата регистрации
        std::string Password;           // Пароль
    };
}