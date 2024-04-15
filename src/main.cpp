#include <string>

#include "parser.h"
#include "file.h"

int main(int argc, char *  argv[]) {
    setlocale(LC_ALL, "ru");

    std::string dataset_path = "../../data/dataset_task.txt";
    std::string final_path = "../../data/final.txt";

    switch (argc) {
        case 2:
            dataset_path = argv[1];
            break;
        case 3:
            dataset_path = argv[1];
            final_path = argv[2];
            break;
        default: break;
    }

    core::File file;
    json::Parser parser;

    return 0;
}