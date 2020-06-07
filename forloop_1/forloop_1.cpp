#include <iostream>

int sumTo(int to)
{
	int sum{ 0 };
	for (int counter{ 1 }; counter <= to; counter++)
		sum += counter;
	return sum;
}

int breakOrReturn()
{
    while (true) // infinite loop
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch;
        std::cin >> ch;

        if (ch == 'b')
            break; // execution will continue at the first statement beyond the loop

        if (ch == 'r')
            return 1; // return will cause the function to immediately return to the caller (in this case, main())
    }

    // breaking the loop causes execution to resume here

    std::cout << "We broke out of the loop\n";

    return 0;
}

int main()
{
    int returnValue{ breakOrReturn() };
    std::cout << "Function breakOrReturn returned " << returnValue << '\n';
	std::cout << sumTo(5) << "\n";
	for (int count{ 0 }; count <= 20; count += 2)
		std::cout << count;
	return 0;
}