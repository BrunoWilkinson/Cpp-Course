#include <iostream>
#include <array>
#include <numeric>

enum ItemTypes
{
	ITEM_HEALTH_POTION,
	ITEM_TORCH,
	ITEM_ARROW,
	MAX_ITEMS,
};

using backpack_type = std::array<int, ItemTypes::MAX_ITEMS>;

void countTotalItems(backpack_type &backpack)
{
	std::cout << "The player has " << std::accumulate(backpack.begin(), backpack.end(), 0) << " items in his backpack.\n";
}

int main()
{
	backpack_type backpack{ 2, 5, 10};
	countTotalItems(backpack);
	std::cout << "The player has " << backpack[ItemTypes::ITEM_TORCH] << " torch(es)\n";
	return 0;
}