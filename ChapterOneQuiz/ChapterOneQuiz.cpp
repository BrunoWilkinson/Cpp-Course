#include <iostream>

int main()
{
	int firstNumber{ 0 };
	int secondNumber{ 0 };

	std::cout << "Enter an integer: ";
	std::cin >> firstNumber;

	std::cout << "Enter another integer: ";
	std::cin >> secondNumber;

	std::cout << firstNumber << " + " << secondNumber << " is " << firstNumber + secondNumber << ".\n";
	std::cout << firstNumber << " - " << secondNumber << " is " << firstNumber - secondNumber << ".\n";
	return 0;
}