#include <iostream>

int main()
{
    int v = 0;
    int t = 0;
    int s = 0;
    int g = 0;
    std::cin >> v >> t;
    s = v * t;
    g = (109 + (s % 109)) % 109 + 1;
    std::cout << g;
    return 0;
}
