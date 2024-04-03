#include <iostream>

void honoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}

    if (from + to == 4)
    {
        honoi(n, from, 2);
        honoi(n, 2, to);
    }

    else
    {
        int res = 6 - from - to;
        honoi(n - 1, from, res);
        printf("%d %d %d\n", n, from, to);
        honoi(n - 1, res, to);
    }
}

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    honoi(n, 1, 3);

    return EXIT_SUCCESS;
}