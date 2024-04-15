#pragma once

#include "structures.h"

#include <algorithm>
#include <vector>

namespace json {
    class Filter final {
    public:
        static void removeUsersBeforeYear(std::vector<User> &users, int year) {
            const auto &it = std::remove_if(users.begin(),users.end(),
            [year](const User& user){
                int user_year = std::stoi(user.RegistrationDate.substr(6));
                return user_year < year;
            });
            users.erase(it, users.end());
        }
    };
}