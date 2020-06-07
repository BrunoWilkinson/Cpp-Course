#include <iostream>

int getSmallNumber()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}

int getLargeNumber()
{
	std::cout << "Enter a larger integer: ";
	int x{};
	std::cin >> x;
	return x;
}

void swapNumber(int x, int y)
{
	if (x > y)
	{
		std::cout << "Swapping the values \n";
		x = y;
		y = x;
	}
}

int main()
{
	int small{ getSmallNumber() };
	int large{ getLargeNumber() };
	swapNumber(small, large);
	std::cout << "The smaller value is " << small << "\n";
	std::cout << "The larger value is " << large << "\n";
	return 0;
}