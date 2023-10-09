#include <iostream>
#include <cstdlib>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	int cnt = 0;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			++cnt;
		}
	}
	std::cout << cnt;

	free(a);

	return EXIT_SUCCESS;
}
