#include <iostream>
#include <iterator> // for std::size

int main()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    constexpr int numStudents{ static_cast<int>(std::size(scores)) };

    int maxScore{ 0 }; // keep track of our largest score
    int maxIndex{ 0 };

    // now look for a larger score
    for (int student{ 0 }; student < numStudents; ++student)
    {
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
            maxIndex = student;
        }
    }

    std::cout << "The best score was " << maxScore << '\n';
    std::cout << "The student index is " << maxIndex << '\n';

    return 0;
}