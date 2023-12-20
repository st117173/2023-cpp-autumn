#include<iostream>

int n[4]{ 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	d[to][n[to]++] = d[from][--n[from]];
}

void honoy(int count, int from = 1, int to = 3)
{
	if (count == 0)
	{
		return;
	}

	int res = 6 - from - to;

	honoy(count - 1, from, res);
	shift(from, to);
	honoy(count - 1, res, to);
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int topel(int a)
{
	if (n[a] > 0)
	{
		return d[a][n[a] - 1];
	}
	else
	{
		return 27;
	}
}

void sort()
{
	int a = 1;
	int b = 2;
	int c = 3;

	while (n[a] > 0)
	{
		int g = topel(1);
		while (topel(c) < g)
		{
			int t = 0;
			for (int i = 0; i < n[b]; ++i)
			{
				if (d[b][i] < topel(c))
				{
					t++;
				}
			}
			honoy(t, b, c);
			swap(b, c);
		}
		shift(a, c);
	}

	while (n[c] > 0)
	{
		int t = 0;
		for (int i = 0; i < n[b]; ++i)
		{
			if (d[b][i] < topel(c))
			{
				t++;
			}
		}
		honoy(t, b, c);
		swap(b, c);
	}
}

void print(int** d, int* n)
{
	for (int i = 9; i >= 0; --i)
	{
		for (int j = 1; j < 4; j++)
		{
			if (i < n[j])
			{
				std::cout << d[j][i];
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[])
{
	std::cin >> n[1];
	for (int i = n[1] - 1; i >= 0; --i)
	{
		std::cin >> d[1][i];
	}
	sort();

	return EXIT_SUCCESS;
}
