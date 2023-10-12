#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	if (n > 0)
	{
		for (int i = 0; i <= n; ++i)
		{
			std::cout << i << " ";
		}
		for (int i = n - 1; i >= 0; --i)
		{
			std::cout << i << " ";
		}
	}
	else if (n < 0)
	{
		for (int i = 0; i >= n; --i)
		{
			std::cout << i << " ";
		}
		for (int i = n + 1; i <= 0; ++i)
		{
			std::cout << i << " ";
		}
	}

	return EXIT_SUCCESS;
}
