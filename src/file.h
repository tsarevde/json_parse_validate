#pragma once

#include <string>
#include <fstream>
#include <functional>

namespace core {
    template<class T>
    class File final {
    public:
        explicit File() = default;
        explicit File(const std::string &path) { open(path); }
        ~File() { close(); }

        File(const File &) = delete;
        File operator=(const File &) = delete;

        T *open(const std::string &path) {
            _file = T(path);

            if (!_file.is_open()) {
                throw "Не удалось открыть файл, проверьте правильность пути.";
            }

            return &_file;
        }

        void close() { _file.close(); }

        void save(const std::string &data) {
            _file << data << std::endl;
        }

        T &get() { return _file; }

    private:
        T _file;
    };
}