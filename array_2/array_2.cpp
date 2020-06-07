#include <iostream>
#include <iterator>

int getValue()
{
	int value{};
	bool invalidValue{};
	do {
		std::cout << "Enter an index between 1 and 9: ";
		std::cin >> value;
		if (std::cin.fail())
		{
			std::cout << "Invalid value, please try again' \n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			invalidValue = true;
		}
		else
			invalidValue = false;
	} while ((value < 1 || value > 9) || invalidValue);
	return value;
}

int main()
{
	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	constexpr int arrayLength{ static_cast<int>(std::size(array)) };
	int userValue{ getValue() };
	int searchValue{};

	for (int index{ 0 }; index < arrayLength; ++index)
	{
		if (userValue == array[index]) {
			std::cout << "The index of the value " << userValue << " is : " << index << "\n";
			break;
		}
	}
		

	return 0;
}