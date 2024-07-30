#include "ranch.h"

#include "models/bank.h"
#include "models/player.h"

Ranch::Ranch()
    : Building(CardName::RANCH,
               CardType::ANIMAL_HUSBANDRY,
               1,
               IndustryType::PRIMARY_INDUSTRY,
               { 2 })
{
}

void Ranch::doOperateEffect(Player* owner,
                          Player* dice_roller,
                          std::vector<Player*> players,
                          Bank* bank)
{
}