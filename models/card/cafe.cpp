#include "cafe.h"

Cafe::Cafe() : 
    Building(CardName::CAFE, 2, CardType::RESTAURANT , {3}, IndustryType::RESTAURANT)
{
}

void Cafe::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}