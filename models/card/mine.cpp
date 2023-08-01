#include "mine.h"

Mine::Mine() : 
    Building(CardName::MINE, 6, CardType::NATURE_RESOURCES, {9}, IndustryType::PRIMARY_INDUSTRY)
{
}

void Mine::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}