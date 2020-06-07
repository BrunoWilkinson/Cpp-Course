#include <iostream>
#include <functional>

using arithmeticFcn = std::function<int(int, int)>;

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

bool isInvalidOperator(char op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		std::cin.clear();
		return false;
	default:
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return true;
	}
}

int getIntegerInput()
{
	int integer{};
	do {
		std::cout << "Enter an integer: ";
		std::cin >> integer;
	} while (isInvalid());
	return integer;
}

char getOperatorInput()
{
	char op{};
	do {
		std::cout << "Enter an operator (+, -, *, /): ";
		std::cin >> op;
	} while (isInvalid() || isInvalidOperator(op));
	return op;
}

int add(int a, int b)
{
	return a + b;
}

int substract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

arithmeticFcn getArithmeticFunction(char op)
{
	switch (op)
	{
	default:
	case '+': return add;
	case '-': return substract;
	case '*': return multiply;
	case '/': return divide;
	}
}

int main()
{
	int a{ getIntegerInput() };
	char op{ getOperatorInput() };
	int b{ getIntegerInput() };
	arithmeticFcn fcnPtr{ getArithmeticFunction(op) };
	std::cout << a << ' ' << op << ' ' << b << " = " << fcnPtr(a, b) << ".\n";
	return 0;
}