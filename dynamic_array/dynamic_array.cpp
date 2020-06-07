#include <iostream>
#include <string>
#include <algorithm>

bool errorOnInput() 
{
	if (std::cin.fail())
	{
		std::cout << "Invalid input, please try again.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	} 
	return false;
}

int getLength()
{
	int length{ 0 };
	bool invalidInput{ false };
	do {
		std::cout << "How many names you wish to enter?: ";
		std::cin >> length;
		invalidInput = errorOnInput();
	} while (invalidInput);
	return length;
}

void getName(std::string *names, int lengthNames)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int times{ 0 }; times < lengthNames; times++)
	{
		bool invalidInput{ false };
		do {
			std::cout << "Enter name #" << times + 1 << ": ";
			std::getline(std::cin, names[times]);
			invalidInput = errorOnInput();
		} while (invalidInput);
	}
}

int main()
{
	int length{ getLength() };
	std::string* names{ new std::string[length] };
	getName(names, length);
	std::sort(names, names + length);
	std::cout << "Here is your sorted list: \n";
	for (int times{ 0 }; times < length; ++times)
		std::cout << "Name #" << times + 1 << ": " << names[times] << "\n";
	delete[] names;
	return 0;
}