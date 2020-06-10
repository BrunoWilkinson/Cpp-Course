#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>

using guess_list = std::vector<int>;

namespace config
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	constexpr int multiplierMin{ 2 };
	constexpr int multiplierMax{ 4 };
	constexpr int maxWrongAnwswer{ 4 };
}

bool isInvalid()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		return true;
	}
	return false;
}

int getNumberUser(std::string message)
{
	int number{};
	do
	{
		std::cout << message << ' ';
		std::cin >> number;
	} while (isInvalid());
	return number;
}

int getRandomNumber(int min, int max)
{
	std::uniform_int_distribution die{ min, max };
	return die(config::mersenne);
}

void startMessage(int size, int multiplier)
{
	std::cout << "I generated " << size << " square numbers. Do you know what each number is after multiplying it by " << multiplier << "? \n";
}

guess_list generateNumbers(int start, int size, int multiplier)
{
	guess_list numbers(static_cast<guess_list::size_type>(size));

	int i{ start };
	for (auto& number : numbers)
	{
		number = ((i * i) * multiplier);
		++i;
	}

	startMessage(size, multiplier);
	return numbers;
}

guess_list generateUserNumbers(int multiplier)
{
	int start{ getNumberUser("Start where?") };
	int size{ getNumberUser("How many?") };

	return generateNumbers(start, size, multiplier);
}

bool findAndRemove(int guess, guess_list& guesses)
{
	auto found{ std::find(guesses.begin(), guesses.end(), guess) };
	if (found == guesses.end())
	{
		return false;
	}
	guesses.erase(found);
	return true;
}

int findClosest(int guess, const guess_list& guesses)
{
	return *std::min_element(guesses.begin(), guesses.end(), [=](int a, int b) {
		return (std::abs(a - guess) < std::abs(b - guess));
		});
}

void printSuccess(guess_list::size_type guessesLeft)
{
	if (guessesLeft == 0)
	{
		std::cout << "You found all numbers, good job \n";
	}
	else
	{
		std::cout << "Nice! " << guessesLeft << " number(s) left.\n";
	}
}

void printFailed(int guess, const guess_list& guesses)
{
	int closest{ findClosest(guess, guesses) };
	std::cout << guess << " is wrong! ";
	if (std::abs(closest - guess) <= config::maxWrongAnwswer)
	{
		std::cout << "Try " << closest << " next time\n";
	}
	else
	{
		std::cout << '\n';
	}
}

bool playGame(guess_list& guesses)
{
	int guess{ getNumberUser(">") };
	if (findAndRemove(guess, guesses))
	{
		printSuccess(guesses.size());
		return !guesses.empty();
	}
	printFailed(guess, guesses);
	return false;
}

int main()
{
	
	int multiplier{ getRandomNumber(config::multiplierMin, config::multiplierMax) };
	guess_list guesses{ generateUserNumbers(2) };
	while (playGame(guesses));
	return 0;
}