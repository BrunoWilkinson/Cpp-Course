#include <iostream>
#include <iterator>
#include <algorithm>

void sortArrayAsc(int array[], int length)
{
	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
	{
		int smallestIndex{ startIndex };
		for (int currentIndex{ smallestIndex + 1 }; currentIndex < length; ++currentIndex)
		{
			if (array[smallestIndex] > array[currentIndex])
				smallestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

void sortArrayDesc(int array[], int length)
{
	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
	{
		int largestIndex{ startIndex };
		for (int currentIndex{ largestIndex + 1 }; currentIndex < length; ++currentIndex)
		{
			if (array[largestIndex] < array[currentIndex])
				largestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[largestIndex]);
	}
}

void printArray(int array[], int length)
{
	for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << " ";
}

int main()
{
	int array[]{ 30, 60, 20, 50, 40, 10 };
	constexpr int length{ static_cast<int>(std::size(array)) };
	// sortArrayAsc(array, length);
	sortArrayDesc(array, length);
	printArray(array, length);
	return 0;
}