#include <iostream>

int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

bool isEven(int x)
{
    return (x % 2) == 0;
}

void printNumber(int x)
{
    if (isEven(x))
    {
        std::cout << x << " is even";
    }
    else 
    {
        std::cout << x << " is odd";
    }
}

int main()
{
    int x{ getInteger() };
    printNumber(x);
    return 0;
}
