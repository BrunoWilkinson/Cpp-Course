#include <iostream>

int getNumber()
{
	std::cout << "Enter a number: ";
	int number{};
	std::cin >> number;
	return number;
}

char getOperator()
{
	std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
	char op{};
	std::cin >> op;
	return op;
}

int calculate(int x, int y, char op)
{
	switch (op)
	{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		case '%':
			return x % y;
		default:
			std::cout << "calculate(): Unhandled case\n";
			return 0;
	}
}

int main()
{
	int x{ getNumber() };
	char op{ getOperator() };
	int y{ getNumber() };
	std::cout << x << ' ' << op << ' ' << y << " is " << calculate(x, y, op) << '\n';
	return 0;
}