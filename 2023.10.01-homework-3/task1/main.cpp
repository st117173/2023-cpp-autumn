#include <iostream>

int main()
{
	int n = 0;
	std::cin >> n;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < ((num * (num + 1)) / 2))
		{
			std::cout << num << " ";
		}
		else
		{
			num++;
			std::cout << num << " ";
		}
	}
	return 0;
}