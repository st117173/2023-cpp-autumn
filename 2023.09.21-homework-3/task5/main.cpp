#include <iostream>

int main()
{
	int k = 0;
	int c = 0;
	std::cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int j = i;
		int g = 0;
		while (j > 0)
		{
			g = j % 10 + g * 10;
			j = j / 10;
		}
		if (g == i)
		{
			c += 1;
		}

	}
	std::cout << c;
	return 0;
}