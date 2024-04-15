#include <iostream>

#include "parser.h"
#include "file.h"

int main(int argc, char *  argv[]) {
    setlocale(LC_ALL, "ru");

    std::string dataset_path = "../../data/dataset_task.txt";
    std::string save_path = "../../data/final.txt";
    const std::string parse_pattern = R"(\[\{"UserID":[0-9]{1,64},"UserName":".{1,64}","UserSurname":".{1,64}","RegistrationDate":".{1,32}","Password":".{1,128}"\}\])";

    // Разбираем ключи запуска (не обработанные данные/обработанные данные)
    switch (argc) {
        case 2:
            dataset_path = argv[1];
            break;
        case 3:
            dataset_path = argv[1];
            save_path = argv[2];
            break;
        default: break;
    }

    try {
        // Открываем файл с датасетом
        core::File<std::ifstream> dataset_file(dataset_path);

        // Создаем парсер и устанавливаем паттерн
        json::Parser dataset_parser;
        dataset_parser.setPattern(parse_pattern);

        // Парсим список пользователей
        const auto &data = dataset_parser.parse(dataset_file.get());
        if (data.empty()) {
            std::cout << "Корректные данные о пользователях не найдены!" << std::endl;
            return 0;
        }

        // Открываем файл и сохраняем карточки пользователей
        core::File<std::ofstream> save_file(save_path);
        for (const auto& obj : data) {
            save_file.save(obj);
        }
    } catch (const std::string &e) {
        // Просто падаем с ошибкой)
        std::cout << e << std::endl;
    }
    catch (...) {
        std::cout << "Произошла непредвиденная ошибка..." << std::endl;
    }

    std::cout << "Найденные данные сохранены в файл: " << save_path << std::endl;
    return 0;
}