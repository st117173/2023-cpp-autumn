#include <iostream>

int main()
{
    int k = 0;
    int g = 0;
    std::cin >> k;
    g = k * 10 + 9;
    g = g * 10 + (9 - k);
    std::cout << g;
    return 0;
}
