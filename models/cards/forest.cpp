#include "forest.h"

#include "models/bank.h"
#include "models/player.h"

Forest::Forest()
    : Building(CardName::FOREST,
               CardType::NATURE_RESOURCES,
               3,
               IndustryType::PRIMARY_INDUSTRY,
               { 5 })
{
}

void Forest::doOperateEffect(Player* owner,
                           Player* dice_roller,
                           std::vector<Player*> players,
                           Bank* bank)
{
}