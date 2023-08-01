#include "ranch.h"

Ranch::Ranch() : 
    Building(CardName::RANCH, 1, CardType::ANIMAL_HUSBANDRY, {2}, IndustryType::PRIMARY_INDUSTRY)
{
}

void Ranch::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}