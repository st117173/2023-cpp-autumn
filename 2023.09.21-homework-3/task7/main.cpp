#include <iostream>

int main()
{
	int n = 0;
	int k = 0;
	int i = 1;
	std::cin >> n;
	while (n > i)
	{
		i = i * 2;
		k++;
	}
	std::cout << k;
	return 0;
}