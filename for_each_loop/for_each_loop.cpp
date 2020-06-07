#include <iostream>
#include <string_view>
#include <string>

std::string getUserName()
{
	std::cout << "Enter a name: ";
	std::string username{};
	std::getline(std::cin, username);
	return username;
}

int main()
{
	std::string_view names[9] = { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
	std::string username{ getUserName() };
	bool found{ false };
	for (std::string_view& name : names)
	{
		if (username == name) 
		{
			found = true;
			break;
		}
	}

	if(found)
		std::cout << username << " was found.\n";
	else
		std::cout << username << " wasn't found.\n";

	return 0;
}