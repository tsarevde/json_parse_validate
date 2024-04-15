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
        /**
        * @brief Устанавливает паттерн для поиска в файле
        * @param pattern Ссылка на строку с паттерном std::regex
        */
        void setPattern(const std::string &pattern);

        /**
        * @brief Парсит файл
        * @param file Ссылка на файловый поток
        * @return Вектор пользователей
        */
        std::vector<structures::User> &parse(std::ifstream &file);

    private:
        /**
        * @brief Разбор строки на структуру
        * @param string Ссылка на сырую строку из файла
        */
        void getUser(const std::string &string);

    private:
        std::regex _pattern;
        std::vector<structures::User> _users;
    };
}
