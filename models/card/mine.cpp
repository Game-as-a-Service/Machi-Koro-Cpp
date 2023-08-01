#include "mine.h"

Mine::Mine() : 
    Building(CardName::MINE, 6, CardType::NATURE_RESOURCES, {9}, IndustryType::PRIMARY_INDUSTRY)
{
}

void Mine::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}