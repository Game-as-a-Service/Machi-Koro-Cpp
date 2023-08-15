#include "apple_orchard.h"

AppleOrchard::AppleOrchard() : 
    Building(CardName::APPLE_ORCHARD, 3, CardType::CROP, {10}, IndustryType::PRIMARY_INDUSTRY)
{
}

void AppleOrchard::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}