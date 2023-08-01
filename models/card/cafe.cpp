#include "cafe.h"

Cafe::Cafe() : 
    Building(CardName::CAFE, 2, CardType::RESTAURANT , {3}, IndustryType::RESTAURANT)
{
}

void Cafe::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}