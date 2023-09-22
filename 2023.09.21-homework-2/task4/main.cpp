#include <iostream>

int main()
{
    int t1 = 15;
    int t5 = 70;
    int t10 = 125;
    int t20 = 230;
    int t60 = 440;
    int n = 0;
    int g1 = 0;
    int g5 = 0;
    int g10 = 0;
    int g20 = 0;
    int g60 = 0;

    std::cin >> n;

    g60 = n / 60;
    n %= 60;
    g20 = n / 20;
    n %= 20;
    g10 = n / 10;
    n %= 10;
    g5 = n / 5;
    g1 = n % 5;
    if (g1 * t1 >= t5)
    {
        g1 = 0;
        g5++;
    }
    if (g1 * t1 + g5 * t5 >= t10)
    {
        g1 = 0;
        g5 = 0;
        g10++;
    }
    if (g1 * t1 + g5 * t5 + g10 * t10 >= t20)
    {
        g1 = 0;
        g5 = 0;
        g10 = 0;
        g20++;
    }
    if (g1 * t1 + g5 * t5 + g10 * t10 + g20 * t20 >= t60)
    {
        g1 = 0;
        g5 = 0;
        g10 = 0;
        g20 = 0;
        g60++;
    }
    std::cout << g1 << " " << g5 << " " << g10 << " " << g20 << " " << g60;
    return 0;
}