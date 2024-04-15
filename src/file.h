#pragma once

#include <string>
#include <fstream>
#include <functional>

namespace core {
    template<class T>
    class File final {
    public:
        explicit File() = default;
        /**
        * @brief Конструктор класса File.
        * @param path Ссылка на строку с расположением файла
        */
        explicit File(const std::string &path) { open(path); }
        ~File() { close(); }

        File(const File &) = delete;
        File operator=(const File &) = delete;

        /**
        * @brief Открывает файл по указаному пути
        * @param path Ссылка на строку с расположением файла
        * @return Указать на файл
        */
        T *open(const std::string &path) {
            _file = T(path);

            if (!_file.is_open()) {
                throw "Не удалось открыть файл, проверьте правильность пути.";
            }

            return &_file;
        }
        /**
        * @brief Закрывает файл
        */
        void close() { _file.close(); }

        /**
        * @brief Записывает строку в файл
        * @param data Ссылка на строку с данными для записи
        */
        void save(const std::string &data) {
            _file << data << std::endl;
        }

        /**
        * @brief Возращает указатель на <T> _file
        * @return Указать на файлs
        */
        T &get() { return _file; }

    private:
        T _file;
    };
}