#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int n = 0;
    
    std::cin >> a;
    std::cin >> b;
    std::cin >> n;

    c = a;
    d = b;

    while (d != 0) 
    {
        e = c % d;
        c = d;
        d = e;
    }

    if (((n > a) && (n > b)) || (n % c != 0))
    {
        std::cout << "Impossible";
    }
    else
    {
        int m = 0;
        while (1 != 0) 
        {
            if (n == a)
            {
                std::cout << ">" << "A\n";
                break;
            }
            if (n == b)
            {
                std::cout << ">" << "B\n";
                break;
            }
            if (a > b) 
            {
                m = m + b;
                std::cout << ">" << "B\n";
                std::cout << "B" << ">" << "A\n";
                if (m >= a)
                {
                    std::cout << "A" << ">\n";
                    std::cout << "B" << ">" << "A\n";
                    m = m % a;
                }
            }
            else 
            {
                m = m + a;
                std::cout << ">" << "A\n";
                std::cout << "A" << ">" << "B\n";
                if (m >= b)
                {
                    std::cout << "B" << ">\n";
                    std::cout << "A" << ">" << "B\n";
                    m = m % b;
                }
            }
            if ((m == n) || (m == 0))
            {
                break;
            }
        }
    }
    return 0;
}
