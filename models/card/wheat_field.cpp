#include "wheat_field.h"

WheatField::WheatField() : 
    Building("Wheat Field", 1, CardType::CROP, { 1 }, IndustryType::PRIMARY_INDUSTRY)
{
}

void WheatField::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}