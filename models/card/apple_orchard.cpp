#include "apple_orchard.h"

AppleOrchard::AppleOrchard() : 
    Building(CardName::APPLE_ORCHARD, 3, CardType::CROP, {10}, IndustryType::PRIMARY_INDUSTRY)
{
}

void AppleOrchard::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}