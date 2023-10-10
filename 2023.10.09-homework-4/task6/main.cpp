#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	int max = *a;
	int min = *a;
	int max_i = 0;
	int min_i = 0;

	for (int i = 0; i < n; ++i)
	{
		if (max <= *(a + i))
		{
			max = *(a + i);
			max_i = i;
		}
		if (min > *(a + i))
		{
			min = *(a + i);
			min_i = i;
		}
	}
	*(a + min_i) = max;
	*(a + max_i) = min;

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}

	free(a);
	return EXIT_SUCCESS;
}
