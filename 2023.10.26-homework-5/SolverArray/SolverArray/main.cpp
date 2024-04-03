#include <iostream>
#include <cstdlib>

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
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	bool exit = false;
	while (!exit)
	{
		printMenu();
		int menu = -1;
		std::cin >> menu;
		switch (menu)
		{

		}
	}
}