#include "line.h"
#include "output.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    int* line = nullptr;
    int size = 0;
    int res = -1;
    int n = 0;
    bool exit = false;
    while (!exit)
    {
        system("cls");
        printMenu();
        int menu = -1;
        int element = 0;
        int index = 0;
        std::cin >> menu;
        switch (menu)
        {
            case 0:
                exit = true;
                break;
            case 1:
                printLine(line, size);
                system("pause");
                break;
            case 2:
                std::cout << "Введите элемент" << std::endl;
                std::cin >> element;
                addElement(line, size, element);
                break;
            case 3:
                while (res == -1) {
                    std::cout << "Введите индекс элемента" << std::endl;
                    std::cin >> index;
                    res = extractElement(line, size, index);
                }
                break;
            case 4:
                lineHeapSort(line, size);
                break;
            case 5:
                lineReverse(line, size);
                printLine(line, size);
                system("pause");
                break;
            case 6:
                lineSwitch(line, size);
                break;
            case 7:
                lineDeleteDuplicate(line, size);
                break;
            case 8:
                std::cout << "Введите n" << std::endl;
                std::cin >> n;
                lineRandom(line, size, n);
                break;
            default:
                std::cout << "Извините, такая опция отстутсвует" << std::endl;
                break;
        }
    }

    free(line);
    return EXIT_SUCCESS;
}
