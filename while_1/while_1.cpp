#include <iostream>

// ASCII 97 to 122

int main()
{
	char myChar{ 'a' };
	while (myChar <= 'z')
	{
		std::cout << myChar << ' ' << static_cast<int>(myChar) << '\n';
		++myChar;
	}
	return 0;
}