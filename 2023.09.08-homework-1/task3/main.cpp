#include <iostream>

int main()
{
    long long n = 0;
    std::cin >> n;
    n = n / 10;
    n = n * (n + 1);
    n = n * 100 + 25;
    std::cout << n;
    return 0;
}
