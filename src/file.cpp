#include "file.h"
#include <iostream>

namespace core {
    File::File() {
        std::cout << "file" << std::endl;
    }
    File::~File() {
        closeFile();
    }
}