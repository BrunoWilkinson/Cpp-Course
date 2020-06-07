#include "constants.h"
#include <iostream>
#include <math.h>


double getTowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

double calculateHeight(double towerHeight, int seconds)
{
	double distanceFallen{ (constants::gravity * pow(seconds, 2)) / 2 };
	double currentHeight{ towerHeight - distanceFallen };

	return currentHeight;
}

void printHeight(double towerHeight, int seconds)
{
	if (towerHeight > 0.0) 
	{
		std::cout << "At " << seconds << " seconds, the ball is at height : " << towerHeight << "\n";
	} 
	else
	{
		std::cout << "At 5 seconds, the ball is on the ground.\n";
	}
}

void calculateAndPrintHeight(int seconds, double towerHeight)
{
	double height{ calculateHeight(towerHeight, seconds) };
	printHeight(height, seconds);
}


int main()
{
	double towerHeight{ getTowerHeight() };
	calculateAndPrintHeight(0, towerHeight);
	calculateAndPrintHeight(1, towerHeight);
	calculateAndPrintHeight(2, towerHeight);
	calculateAndPrintHeight(3, towerHeight);
	calculateAndPrintHeight(4, towerHeight);
	calculateAndPrintHeight(5, towerHeight);
	return 0;
}