#include <iostream>

int main()
{
	int outer{ 5 };
	while (outer >= 1)
	{
		// loop between inner and 1
		int inner{ outer };
		while (inner >= 1)
		{
			std::cout << inner-- << ' ';
		}

		// print a newline at the end of each row
		std::cout << '\n';
		--outer;
	}
	return 0;
}