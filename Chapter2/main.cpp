#include "io.h"

int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	writeAnwser(x + y);
	return 0;
}