#include <iostream>

int main()
{
    int a1 = 0;
    int a2 = 1;
    int a3 = 0;
    int n = 0;
    std::cin >> n;
    if (n == 1)
    {
        std::cout << a2;
    }
    else
    {
        int i = 2;
        while (i <= n)
        {
            a3 = a1 + a2;
            a1 = a2;
            a2 = a3;
            i++;
        }
        std::cout << a2;
    }
    return 0;
}