#include <iostream>

struct Fraction
{
	int numerator;
	int denominator;
};

Fraction getFraction()
{
	Fraction temp;
	std::cout << "Enter a numerator: ";
	std::cin >> temp.numerator;
	std::cout << "Enter a denominator: ";
	std::cin >> temp.denominator;
	return temp;
}

void multiply(Fraction f1, Fraction f2)
{
	std::cout << static_cast<double>(f1.numerator * f2.numerator) / (f1.denominator * f2.denominator);
}

int main()
{
	std::cout << "Enter first fraction \n";
	Fraction f1{ getFraction() };
	std::cout << "Enter second fraction \n";
	Fraction f2{ getFraction() };
	multiply(f1, f2);
	return 0;
}