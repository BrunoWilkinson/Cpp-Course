#include <iostream>

int main()
{
	std::cout << "Hello, world!" << std::endl;
	std::cout << "Enter a number: ";
	int x{ };
	std::cin >> x;
	std::cout << "You entered " << x << "\n";
	return 0;
}