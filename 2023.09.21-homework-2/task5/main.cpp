#include <iostream>

int main()
{
	int n = 0;
	int a = 0;
	std::cin >> n;
	a = n % 10;

	switch (a)
	{
	case 1:
		if ((n % 100) == 11) {
			std::cout << n << " " << "bochek";
			break;
		}
		else {
			std::cout << n << " " << "bochka";
			break;
		}
	case 2: case 3: case 4:
		if (((n % 100) == 12) || ((n % 100) == 13) || ((n % 100) == 14)) {
			std::cout << n << " " << "bochek";
			break;
		}
		else {
			std::cout << n << " " << "bochki";
			break;
		}
	default:
		std::cout << n << " " << "bochek";
		break;
	}
	return 0;

}