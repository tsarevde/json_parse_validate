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
        save_file.get() << "[" << std::endl;
        for (size_t i = 0; i < data.size(); ++i) {
            save_file.get() << "\t{\n";
            save_file.get() << "\t\t\"UserID\": " << data[i].UserID << ",\n";
            save_file.get() << "\t\t\"UserName\": \"" << data[i].UserName << "\",\n";
            save_file.get() << "\t\t\"UserSurname\": \"" << data[i].UserSurname << "\",\n";
            save_file.get() << "\t\t\"RegistrationDate\": \"" << data[i].RegistrationDate << "\",\n";
            save_file.get() << "\t\t\"Password\": \"" << data[i].Password << "\"\n";
            save_file.get() << "\t}";
            if (i != data.size() - 1) {
                save_file.get() << ",";
            }
            save_file.get() << std::endl;
        }
        save_file.get() << "]" << std::endl;
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