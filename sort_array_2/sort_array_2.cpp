#include <iostream>
#include <iterator>
#include <algorithm>

void bubbleSort(int array[], int length)
{
	for (int iteration{ 0 }; iteration < length - 1; ++iteration)
	{
		int lastIndex{ length - iteration };
		bool hasSwap{ false };
		for (int index{ 0 }; index < lastIndex - 1; ++index)
		{
			int nextIndex{ index + 1 };
			if (array[index] > array[nextIndex]) 
			{
				std::swap(array[index], array[nextIndex]);
				hasSwap = true;
			}
		}
		
		if (!hasSwap) 
		{
			std::cout << "Early termination on iteration: " << iteration + 1 << '\n';
			break;
		}
	}
}

int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ static_cast<int>(std::size(array)) };
	bubbleSort(array, length);
	for (int count{ 0 }; count < length; ++count)
		std::cout << array[count] << " ";
	return 0;
}