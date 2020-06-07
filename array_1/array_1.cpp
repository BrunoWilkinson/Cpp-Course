#include <iostream>

namespace Animals
{
	enum Animlas
	{
		CHICKEN,
		DOG,
		CAT,
		ELEPHANT,
		DUCK,
		SNAKE,
		MAX_ANIMALS,
	};
}

int main()
{
	int legs[Animals::MAX_ANIMALS] = { 2, 4, 4, 4, 2, 0 };
	std::cout << "An elephant has " << legs[Animals::ELEPHANT] << " legs.\n";
	return 0;
}