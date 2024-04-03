#include<iostream>

void honoy(int count, int from = 1, int to = 3)
{
	if (count <= 0)
	{
		return;
	}

	int res = 6 - from - to;

	if (count == 1)
	{
		printf("1 %d %d\n", from, to);
	}
	else
	{
		honoy(count - 1, from, to);
		honoy(count - 2, to, res);
		printf("0 %d %d\n", from, to);
		honoy(count - 2, res, from);
		honoy(count - 1, from, to);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	honoy(n);
	return EXIT_SUCCESS;
}