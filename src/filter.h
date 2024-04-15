#pragma once

#include "structures.h"

#include <algorithm>
#include <vector>

namespace json {
    class Filter final {
    public:
        /**
        * @brief Удаляет пользователей, чей год меньше заданного
        * @param users  Ссылка на вектор пользователей
        * @param year   Год от которого будут вестись расчеты
        */
        static void removeUsersBeforeYear(std::vector<structures::User> &users, int year) {
            const auto &it = std::remove_if(users.begin(),users.end(),
            [year](const structures::User& user){
                int user_year = std::stoi(user.RegistrationDate.substr(6));
                return user_year < year;
            });
            users.erase(it, users.end());
        }
    };
}