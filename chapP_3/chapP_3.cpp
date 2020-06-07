#include <iostream>

int main()
{
	const char* str{ "Hello, world!" };
	while (*str != '\0')
	{
		std::cout << *str;
		++str;
	}
	return 0;
}