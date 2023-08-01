#include "bakery.h"

Bakery::Bakery() : 
    Building(CardName::BAKERY, 1, CardType::CROP, {2,3}, IndustryType::SECONDARY_INDUSTRY)
{
}

void Bakery::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}