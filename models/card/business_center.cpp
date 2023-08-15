#include "business_center.h"

BusinessCenter::BusinessCenter() : 
    Building(CardName::BUSINESS_CENTER, 8, CardType::MAJOR_ESTABLISHMENT, {6}, IndustryType::IMPORTANT_BUILDING)
{
}

void BusinessCenter::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}