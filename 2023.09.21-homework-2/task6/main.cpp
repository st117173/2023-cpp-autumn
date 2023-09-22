#include <iostream>

int main() {
    int k = 0;
    int m = 0;
    int n = 0;
    int g = 0;
    std::cin >> k;
    std::cin >> m;
    std::cin >> n;
    g = (n / k) * 2 * m;
    if (n % k > 0) 
    {
        if ((k / 2) < (n % k)) 
        {
            g = g + m * 2;
        }
        else 
        {
            g = g + m;
        }
    }
    if (n <= k) 
    {
        g = 2 * m;
    }
    std::cout << g;

    return 0;
}