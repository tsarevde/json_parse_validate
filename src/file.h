#pragma once

namespace core {
    namespace std {
        class string;
    }

    class File {
    public:
        File();
        ~File();

    public:
        bool openFile(const std::string &path);
        bool closeFile();

        bool loadData();
        bool saveData();
    };
}