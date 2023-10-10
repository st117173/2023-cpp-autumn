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
	for (int i = 0; i < n; ++i)
	{
		if (max < *(a + i))
		{
			max = *(a + i);
		}
	}
	std::cout << max;
	free(a);

	return EXIT_SUCCESS;
}
