#include <iostream>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int g = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a > b)
	{
		g = a;
		a = b;
		b = g;
	}
	if (b > c)
	{
		g = b;
		b = c;
		c = g;
	}
	if (a > b)
	{
		g = a;
		a = b;
		b = g;
	}
	std::cout << a << " " << b << " " << c;
	return 0;
}