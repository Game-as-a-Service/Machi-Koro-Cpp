#include "ranch.h"

Ranch::Ranch() : 
    Building(CardName::RANCH, 1, CardType::ANIMAL_HUSBANDRY, {2}, IndustryType::PRIMARY_INDUSTRY)
{
}

void Ranch::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}