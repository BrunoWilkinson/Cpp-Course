#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>
#include <numeric>
#include <vector>

enum class CardRank
{
	RANK_TWO,
	RANK_THREE,
	RANK_FOUR,
	RANK_FIVE,
	RANK_SIX,
	RANK_SEVEN,
	RANK_EIGHT,
	RANK_NINE,
	RANK_TEN,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,

	MAX_RANK
};

enum class CardSuit
{
	SUIT_CLUBS,
	SUIT_DIAMONDS,
	SUITS_HEART,
	SUITS_SPADE,

	MAX_SUITS
};

struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

struct Player
{
	int score{};
};

using deck_card_type = std::array<Card, 52>;
using hand_card_type = std::vector<Card>;
using index_type = deck_card_type::size_type;

constexpr int maximumScore{ 21 };
constexpr int minimumDealerScore{ 17 };

std::string printCard(const Card& card)
{
	std::string code{};
	switch (card.rank)
	{
		case CardRank::RANK_JACK:
			code = "J";
			break;
		case CardRank::RANK_QUEEN:
			code = "Q";
			break;
		case CardRank::RANK_KING:
			code = "K";
			break;
		case CardRank::RANK_ACE:
			code = "A";
			break;
		default:
			int number{ static_cast<int>(card.rank) };
			code = std::to_string(number + 2);
	}
	switch (card.suit)
	{
		case CardSuit::SUIT_CLUBS:
			code += "C";
			break;
		case CardSuit::SUIT_DIAMONDS:
			code += "D";
			break;
		case CardSuit::SUITS_HEART:
			code += "H";
			break;
		case CardSuit::SUITS_SPADE:
			code += "S";
			break;
	}
	return code;
}

deck_card_type createDeck()
{
	deck_card_type deck;
	int maxRank{ static_cast<int>(CardRank::MAX_RANK) - 1 };
	int maxSuits{ static_cast<int>(CardSuit::MAX_SUITS) };
	int rankCounter{ 0 };
	int suitCounter{ 0 };
	for (auto& card : deck)
	{
		card.rank = static_cast<CardRank>(rankCounter);
		card.suit = static_cast<CardSuit>(suitCounter);
		if (rankCounter == maxRank)
		{
			++suitCounter;
			rankCounter = 0;
		} 
		else {
			++rankCounter;
		}
	}
	return deck;
}

void printDeck(const deck_card_type& deck)
{
	for (auto& card : deck)
		std::cout << printCard(card) << " ";
	std::cout << '\n';
}

void shuffleDeck(deck_card_type& deck)
{
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card)
{
	// Handle rank 2 - 10. We could do this in the switch, but it would be long.
	if (card.rank <= CardRank::RANK_TEN)
	{
		return (static_cast<int>(card.rank) + 2);
	}

	switch (card.rank)
	{
	case CardRank::RANK_JACK:
	case CardRank::RANK_QUEEN:
	case CardRank::RANK_KING:
		return 10;
	case CardRank::RANK_ACE:
		return 11;
	default:
		// Should never happen. If it does, we have a bug in our code.
		return 0;
	}
}

bool playerWantsHit()
{
	while (true)
	{
		std::cout << "(h) to hit, or (s) to stand: ";
		char ch{};
		std::cin >> ch;
		switch (ch)
		{
		case 'h':
			return true;
		case 's':
			return false;
		}
	}
}

bool playerTurn(const deck_card_type& deck, index_type& nextCardIndex, Player& player)
{
	while (true)
	{
		std::cout << "You have " << player.score << '\n';
		if (player.score > maximumScore)
			return true;
		else
		{
			if (playerWantsHit())
			{
				player.score += getCardValue(deck[nextCardIndex]);
			}
			else
			{
				return false;
			}
		}
	}
}

bool dealerTurn(const deck_card_type& deck, index_type& nextCardIndex, Player& dealer)
{
	while (dealer.score < minimumDealerScore)
	{
		dealer.score += getCardValue(deck[nextCardIndex++]);
	}
	return (dealer.score > maximumScore);
}

bool playBlackjack(const deck_card_type& deck)
{
	index_type nextCardIndex{ 0 };
	Player dealer{ getCardValue(deck[nextCardIndex++]) };
	std::cout << "The dealer is showing: " << dealer.score << '\n';
	Player player{ getCardValue(deck[nextCardIndex++]) + getCardValue(deck[nextCardIndex++]) };
	nextCardIndex += 2;
	if (playerTurn(deck, nextCardIndex, player))
		return false;
	if (dealerTurn(deck, nextCardIndex, player))
		return true;
	return (player.score > dealer.score);
}

int main()
{
	auto deck{ createDeck() };

	shuffleDeck(deck);

	if (playBlackjack(deck))
	{
		std::cout << "You win!\n";
	}
	else
	{
		std::cout << "You lose!\n";
	}
	return 0;
}