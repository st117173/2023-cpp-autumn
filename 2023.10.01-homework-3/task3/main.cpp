#include <iostream>

int main()
{
	int x = 0;
	int a = 0;
	int m = 0;
	std::cin >> x;
	for (int i = 1; i <= x; i++)
	{
		if (i * i >= x)
		{
			m = i;
			break;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (x % i == 0)
		{
			a = a + 2;
		}
	}
	if (x % m == 0)
	{
		a--;
	}
	std::cout << a;
	return 0;
}