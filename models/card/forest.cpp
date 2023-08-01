#include "forest.h"

Forest::Forest() : 
    Building(CardName::FOREST, 3, CardType::NATURE_RESOURCES, {5}, IndustryType::PRIMARY_INDUSTRY)
{
}

void Forest::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{

}