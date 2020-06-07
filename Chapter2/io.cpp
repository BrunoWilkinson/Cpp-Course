#include "io.h"
#include <iostream>

int readNumber()
{
	std::cout << "Enter an integer: ";
	int x{ 0 };
	std::cin >> x;
	return x;
}

void writeAnwser(int x)
{
	std::cout << "The answer is: " << x << "\n";
}