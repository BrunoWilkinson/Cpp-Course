#include <iostream>
#include <string>

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	ostrich,
};

std::string getAnimalName(Animal animal)
{
	switch (animal)
	{
		case Animal::pig:
			return "pig";
		case Animal::chicken:
			return "chicken";
		case Animal::goat:
			return "goat";
		case Animal::cat:
			return "cat";
		case Animal::dog:
			return "dog";
		case Animal::ostrich:
			return "ostrich";
		default:
			std::cout << "getAnimalName(): error unrecognised animal \n";
			return "";
	}
}

void printNumberOfLegs(Animal animal)
{
	std::cout << "A " << getAnimalName(animal) << " has ";
	switch (animal)
	{
		case Animal::chicken:
		case Animal::ostrich:
			std::cout << '2';
			break;
		case Animal::pig:
		case Animal::goat:
		case Animal::cat:
		case Animal::dog:
			std::cout << '4';
			break;
		default:
			std::cout << "printNumberOfLegs(): error unrecognised animal \n";
			break;
	}
	std::cout << " legs.\n";
}

int main()
{
	printNumberOfLegs(Animal::cat);
	printNumberOfLegs(Animal::chicken);
	return 0;
}