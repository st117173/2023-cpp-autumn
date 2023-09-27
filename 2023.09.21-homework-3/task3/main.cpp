#include <iostream>
#include <math.h>

int main()
{
	int x = 0;
	int a = 0;
	std::cin >> x;
	int sq = (int)sqrt(x);
	for (int i = 1; i <= sq; i++)
	{
		if (x % i == 0)
		{
			if (i * i == x)
			{
				a = a + 1;
			}
			else
			{
				a = a + 2;
			}
		}
	}
	std::cout << a;
	return 0;
}