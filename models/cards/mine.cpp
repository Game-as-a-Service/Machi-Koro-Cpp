#include "mine.h"

#include "models/bank.h"
#include "models/player.h"

Mine::Mine()
    : Building(CardName::MINE, CardType::NATURE_RESOURCES, 6, IndustryType::PRIMARY_INDUSTRY, { 9 })
{
}

void Mine::operateEffect(Player* owner,
                         Player* dice_roller,
                         std::vector<Player*> players,
                         Bank* bank)
{
}