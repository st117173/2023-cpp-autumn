#include <iostream>
#include <cstdlib>

void printMenu()
{
	std::cout << "0 - ����� �� ���������" << std::endl;
	std::cout << "1 - ������� ������" << std::endl;
	std::cout << "2 - �������� ������� � ������" << std::endl;
	std::cout << "3 - ������� ������� �� �������" << std::endl;
	std::cout << "4 - ������������� ������ �� �����������" << std::endl;
	std::cout << "5 - ���������� ������" << std::endl;
	std::cout << "6 - �������� ������� ������������ � ����������� ������� �������" << std::endl;
	std::cout << "7 - ������� �� ������� ��� ���������" << std::endl;
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