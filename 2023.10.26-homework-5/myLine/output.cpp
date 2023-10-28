#include "output.h"
void printMenu()
{
    std::cout << "0 - Выход из программы" << std::endl;
    std::cout << "1 - Вывести массив" << std::endl;
    std::cout << "2 - Добавить элемент в массив" << std::endl;
    std::cout << "3 - Удалить элемент из массива" << std::endl;
    std::cout << "4 - Отсортировать массив по возрастанию" << std::endl;
    std::cout << "5 - Развернуть массив" << std::endl;
    std::cout << "6 - Поменять местами максимальный и минимальный элемент массива" << std::endl;
    std::cout << "7 - Удалить из массива все дубликаты" << std::endl;
    std::cout << "8 - Добавить в массив n случайных элементов" << std::endl;

}

void printError()
{
    std::cout << "Массива не существует" << std::endl;
}

void printLine(int* line, int size)
{
    if (line == nullptr)
    {
        std::cout << "Массива нет" << std::endl;
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << line[i] << std::endl;
        }
    }
}
