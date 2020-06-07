#include<iostream>

bool isPrime(int x)
{
	if (x == 2)
		return true;
	else if (x == 3)
		return true;
	else if (x == 5)
		return true;
	else if (x == 7)
		return true;
	else
		return false;
}

int main()
{
	std::cout << "Enter a integer: ";
	int number{};
	std::cin >> number;
	if (isPrime(number))
	{
		std::cout << "The digit is prime";
	}
	else 
	{
		std::cout << "The digit is not prime";
	}
}