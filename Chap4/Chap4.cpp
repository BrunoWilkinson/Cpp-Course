#include<iostream>

double askNumber()
{
	std::cout << "Enter a double value: ";
	double x{ 0 };
	std::cin >> x;
	return x;
}

char getOperator()
{
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char op{ ' ' };
	std::cin >> op;
	return op;
}

void printResult(double x, double y, char op)
{
	if (op == '+')
		std::cout << x << " + " << y << " is " << x + y;
	else if (op == '-')
		std::cout << x << " - " << y << " is " << x - y;
	else if (op == '*')
		std::cout << x << " * " << y << " is " << x * y;
	else if (op == '/')
		std::cout << x << " / " << y << " is " << x / y;
}

int main()
{
	double x{ askNumber() };
	double y{ askNumber() };
	char op{ getOperator() };
	
	printResult(x, y, op);

	return 0;
}