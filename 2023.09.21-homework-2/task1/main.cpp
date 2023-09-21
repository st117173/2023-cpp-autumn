#include <iostream>

int main() {
	int n = 0;
	std::cin >> n;
	if (((n % 4) == 0) && ((n % 100) != 0) && ((n % 400) == 0))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	return 0;
}