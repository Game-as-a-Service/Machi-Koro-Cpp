#include "forest.h"

Forest::Forest() : 
    Building(CardName::FOREST, 3, CardType::NATURE_RESOURCES, {5}, IndustryType::PRIMARY_INDUSTRY)
{
}

void Forest::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{

}