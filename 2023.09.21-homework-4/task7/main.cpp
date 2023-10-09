#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			count++;
		}
	}
	int* b = (int*)malloc(sizeof(int) * count);
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			*(b + index) = *(a + i);
			++index;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < count; ++i)
	{
		std::cout << *(b + i) << " ";
	}
	std::cout << std::endl;
	std::cout << (sizeof(a) * n) / sizeof(*a);
	std::cout << std::endl;
	std::cout << (sizeof(b) * count) / sizeof(*b);

	free(a);
	free(b);

	return EXIT_SUCCESS;
}
