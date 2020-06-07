#include <iostream>

int getInteger()
{
	std::cout << "Enter a number between 0 and 255: ";
	int number{};
	std::cin >> number;
	return number;
}

int printBit(int number, int pow)
{
	if (number >= pow)
	{
		std::cout << "1";
		return number - pow;
	}
	std::cout << "0";
	return number;
}

void intToBit(int number)
{
	std::cout << "Number to bit: ";
	number = printBit(number, 128);
	number = printBit(number, 64);
	number = printBit(number, 32);
	number = printBit(number, 16);
	std::cout << " ";
	number = printBit(number, 8);
	number = printBit(number, 4);
	number = printBit(number, 2);
	number = printBit(number, 1);
}

int main()
{
	int number{ getInteger() };
	intToBit(number);
	return 0;
}