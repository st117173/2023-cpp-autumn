#include <iostream>

int main() 
{
    int x = 0;
    int a = 0;
    int b = 0;
    std::cin >> x;
    if (x == 100) 
    {
        std::cout << "C";
    }

    a = x % 10;
    x = x / 10;
    b = x % 10;
    x = x / 10;

    switch (b) 
    {
    case 1:
        std::cout << "X";
        break;
    case 2:
        std::cout << "XX";
        break;
    case 3:
        std::cout << "XXX";
        break;
    case 4:
        std::cout << "XL";
        break;
    case 5:
        std::cout << "L";
        break;
    case 6:
        std::cout << "LX";
        break;
    case 7:
        std::cout << "LXX";
        break;
    case 8:
        std::cout << "LXXX";
        break;
    case 9:
        std::cout << "XC";
        break;
    default:
        std::cout << "";
        break;
    }

    switch (a) 
    {
    case 1:
        std::cout << "I";
        break;
    case 2:
        std::cout << "II";
        break;
    case 3:
        std::cout << "III";
        break;
    case 4:
        std::cout << "IV";
        break;
    case 5:
        std::cout << "V";
        break;
    case 6:
        std::cout << "VI";
        break;
    case 7:
        std::cout << "VII";
        break;
    case 8:
        std::cout << "VIII";
        break;
    case 9:
        std::cout << "IX";
        break;
    default:
        std::cout << "";
        break;
    }
}