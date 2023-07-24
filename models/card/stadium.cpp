#include "stadium.h"

Stadium::Stadium() : 
    Building(CardName::STADIUM, 6, CardType::MAJOR_ESTABLISHMENT, {6}, IndustryType::IMPORTANT_BUILDING)
{
}

void Stadium::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}