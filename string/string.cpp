#include <iostream>
#include <string>

std::string getName()
{
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin, name);
	return name;
}

int getAge()
{
	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return age;
}

double ageLetter(int letters, int age)
{
	return static_cast<double>(age) / letters;
}

int main()
{
	std::string name{ getName() };
	int age{ getAge() };
	std::cout << "You've lived " << ageLetter(static_cast<int>(name.length()), age) << " years for each letter in your name.";
	return 0;
}