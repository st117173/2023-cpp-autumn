#include <iostream>
#include <math.h>

int main() 
{
    int n = 0;
    std::cin >> n;
    std::cout << ((n + 1)*(abs(n - 1) + 1)) / 2;
    return 0;
}
