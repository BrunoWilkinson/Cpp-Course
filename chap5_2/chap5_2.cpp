#include <iostream>
#include <random>
#include <ctime>

void play();

namespace MyRandom
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	int min{ 1 };
	int max{ 100 };
}

int getUserGuess(int count)
{
	std::cout << "Guess #" << count << ":";
	int guess{};
	std::cin >> guess;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "getUserGuess(): Not a number\n";
		getUserGuess(count);
	}
	return guess;
}

void playAgain()
{
	char anwser{};
	do {
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> anwser;
	} while (anwser != 'y' && anwser != 'n');
	if (anwser == 'y')
	{
		std::cout << "\033[2J\033[1;1H";
		play();
	}
	else
		std::cout << "Thank you for playing.\n";
}

void play()
{
	std::uniform_int_distribution guessRandom{ MyRandom::min, MyRandom::max };
	int guessNumber{ guessRandom(MyRandom::mersenne) };
	int count{ 1 };
	do {
		int guess{ getUserGuess(count) };
		if (guess > guessNumber) {
			std::cout << "Your guess is too high.\n";
		}
		else if (guess < guessNumber)
		{
			std::cout << "Your guess is too low.\n";
		}
		else
		{
			std::cout << "Correct! You win!\n";
			break;
		}
		++count;
	} while (count <= 7);
	playAgain();
}

int main()
{
	play();
	return 0;
}