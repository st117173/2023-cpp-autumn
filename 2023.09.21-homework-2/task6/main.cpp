#include <iostream>

int main()
{
	int k = 0;
	int m = 0;
	int n = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	m = (k / n) * 2 * m;
	std::cout << m;
	return 0;

}