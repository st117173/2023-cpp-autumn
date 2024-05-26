#include "ConsoleHandler.h"
#include <chrono>
#include <fstream> // Добавление заголовочного файла для std::ofstream
#include <iostream>

void ConsoleHandler::correct(int &checkNumber)
{
    // Попытка считать число
    while (!(std::cin >> checkNumber))
    {
        // Если ввод некорректен, выводим сообщение
        std::cout << "Введите другое число: ";
        // Сбрасываем ошибочное состояние потока
        std::cin.clear();
        // Пропускаем максимальное количество символов до следующего перевода строки
        std::cin.ignore(10000, '\n'); // Здесь 10000 как пример большого числа
    }
}

void ConsoleHandler::run()
{
    StringSearch ss;
    int choice;
    while (true)
    {
        std::cout << "Выберите опцию:\n1 – Ввод с консоли\n2 – Ввод из файла\n3 – Выход\n";
        correct(choice);

        if (choice == 3)
        {
            break;
        }

        std::string text, pattern;
        if (choice == 1)
        {
            std::cin.ignore(); // Чтобы пропустить оставшийся символ новой строки

            std::cout << "Введите текст: ";
            std::getline(std::cin, text);

            std::cout << "Введите шаблон: ";
            std::getline(std::cin, pattern);
        }
        else if (choice == 2)
        {
            std::cin.ignore(); // Чтобы пропустить оставшийся символ новой строки

            std::string filename;
            std::cout << "Введите имя файла: ";
            std::getline(std::cin, filename);

            if (!ss.getInputFromFile(filename, text))
            {
                continue;
            }

            std::cout << "Введите строку для поиска в файле: ";
            std::getline(std::cin, pattern);
        }
        else
        {
            std::cout << "Недопустимый выбор опции.\n";
            continue;
        }

        std::cout << "Выберите алгоритм:\n1 – Кнута-Морриса-Пратта\n2 – Ахо-Корасик\n";
        correct(choice);
        std::cin.ignore(); // Чтобы пропустить оставшийся символ новой строки

        std::cout << "Выберите опцию вывода:\n1 – Вывод в консоль\n2 – Вывод в файл\n";
        correct(choice);
        std::cin.ignore(); // Чтобы пропустить оставшийся символ новой строки

        std::ofstream outFile;
        std::ostream *outStream = &std::cout;

        if (choice == 2)
        {
            std::string outFilename;

            std::cout << "Введите имя файла для вывода: ";
            std::getline(std::cin, outFilename);
            outFile.open(outFilename);
            if (!outFile.is_open())
            {
                std::cerr << "Не удалось открыть файл для вывода: " << outFilename << std::endl;
                continue;
            }
            outStream = &outFile;
        }

        auto start = std::chrono::high_resolution_clock::now();
        ss.findPatterns(text, pattern, choice, *outStream);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        *outStream << "Время выполнения: " << duration.count() << " секунд." << std::endl;

        if (outFile.is_open())
        {
            outFile.close();
        }
    }
}
