#include <iostream>

int getUserInput()
{
	int x{ 0 };
	std::cout << "Enter an integer: ";
	std::cin >> x;
	return x;
}

int doubleNumber(int x)
{
	return x * 2;
}

int main()
{
	std::cout << doubleNumber(getUserInput());
	return 0;
}