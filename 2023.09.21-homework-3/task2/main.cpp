#include <iostream>

int main()
{
	int x = 0;
	int y = 0;
	std::cin >> x;
	while (x > 0)
	{
		y = x % 10 + y * 10;
		x = x / 10;
	}
	std::cout << y;
	return 0;
}