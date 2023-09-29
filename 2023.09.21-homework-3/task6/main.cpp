#include <iostream>

int main()
{
	int n = 0;
	int a1 = 0;
	int a2 = 1;
	int b = 0;
	std::cin >> n;
	while (n > 0)
	{
		b = a2;
		a2 = a1 + a2;
		a1 = b;
		n = n - 1;
	}


}
