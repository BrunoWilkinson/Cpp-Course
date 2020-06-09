#include <iostream>

int factorial(int n)
{
	if (n <= 0)
		return 1;
	return factorial(n - 1) * n;
}

int sumDigit(int x)
{
	if (x < 10)
		return x;
	else
		return sumDigit(x / 10) + x % 10;
}

bool isInvalid()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return true;
	}
	return false;
}

int getUserNumber()
{
	do
	{
		std::cout << "Please enter a number: ";
		int number{};
		std::cin >> number;
		return number;
	} while (isInvalid);
}

void printBinary(unsigned int x)
{
	if (x > 1)
		printBinary(x / 2);
	std::cout << x % 2;
}

int main()
{
	for (int count{ 1 }; count < 7; ++count)
		std::cout << "Fractorial: " << factorial(count) << '\n';
	std::cout << "SumDigit: " << sumDigit(93427) << '\n';
	int number{ getUserNumber() };
	std::cout << "Binary:\n";
	printBinary(number);
	return 0;
}