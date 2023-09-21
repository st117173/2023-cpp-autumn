#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int g = 0;
    std::cin >> a >> b;
    g = (a > b) * a + (b >= a) * b;
    std::cout << g;
    return 0;
}
