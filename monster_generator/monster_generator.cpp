#include <iostream>
#include <string>
#include <ctime>
#include <array>

class Monster 
{
public:
	enum Type
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES,
	};

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

	std::string getTypeString()
	{
		switch (m_type)
		{
		case DRAGON:
			return "Dragon";
		case GOBLIN:
			return "Goblin";
		case OGRE:
			return "Ogre";
		case ORC:
			return "Orc";
		case SKELETON:
			return "Skeleton";
		case TROLL:
			return "Troll";
		case VAMPIRE:
			return "Vampire";
		case ZOMBIE:
			return "Zombie";
		default:
			return "???";
		}
	}

public:
	Monster(Type type, const std::string& name, const std::string& roar, int hitPoints) : 
		m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
	{

	}
	void print()
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " and says " << m_roar << "\n";
	}
};

class MonsterGenerator 
{
public:
	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	int static getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
	}
	Monster static generateMonster()
	{
		auto type{ static_cast<Monster::Type>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)) };
		int hitPoints{ getRandomNumber(1, 100) };
		static constexpr std::array<const char*, 6> s_names{ "Smaug", "Slime", "Chaos", "Bones", "Bob", "Balarog"};
		static constexpr std::array<const char*, 6> s_roars{ "*rattle*", "*bruh*", "*rooooaarr*", "*coink*", "*boom*", "*sniff*" };
		auto name{ s_names[static_cast<std::size_t>(getRandomNumber(0, s_names.size() - 1))] };
		auto roar{ s_roars[static_cast<std::size_t>(getRandomNumber(0, s_roars.size() - 1))] };
		return Monster(type, name, roar, hitPoints);
	}
};

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // If using Visual Studio, discard first random value
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();
	return 0;
}
