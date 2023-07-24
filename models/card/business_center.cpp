#include "business_center.h"

BusinessCenter::BusinessCenter() : 
    Building(CardName::BUSINESS_CENTER, 8, CardType::MAJOR_ESTABLISHMENT, {6}, IndustryType::IMPORTANT_BUILDING)
{
}

void BusinessCenter::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}