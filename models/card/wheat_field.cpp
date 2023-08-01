#include "wheat_field.h"

WheatField::WheatField() : 
    Building(CardName::WHEAT_FIELD, 1, CardType::CROP, {1}, IndustryType::PRIMARY_INDUSTRY)
{
}

void WheatField::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}