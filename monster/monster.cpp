#include <iostream>
#include <string>

enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giantSpider,
	slime,
};

struct Monster
{
	std::string name;
	int health;
	MonsterType type;
};

std::string getMonsterType(MonsterType type)
{
	if (type == MonsterType::ogre)
		return "Ogre";
	else if (type == MonsterType::dragon)
		return "Dragon";
	else if (type == MonsterType::orc)
		return "orc";
	else if (type == MonsterType::giantSpider)
		return "Giant Spider";
	else if (type == MonsterType::slime)
		return "Slime";
	return "Unknown";
}

void printMonster(Monster monster)
{
	std::cout << "This " << getMonsterType(monster.type) << " is name " << monster.name << " and has " << monster.health << " health. \n";
}

int main()
{
	Monster torg{ "Torg", 145, MonsterType::ogre };
	Monster slime{ "Slime", 23, MonsterType::slime };
	Monster smaug{ "Smaug", 1000000, MonsterType::dragon };
	printMonster(torg);
	printMonster(slime);
	printMonster(smaug);
}