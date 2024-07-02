#include "bakery.h"

#include "models/bank.h"
#include "models/player.h"

Bakery::Bakery()
    : Building(CardName::BAKERY, CardType::CROP, 1, IndustryType::SECONDARY_INDUSTRY, { 2, 3 })
{
}

void Bakery::operateEffect(Player* owner,
                           Player* dice_roller,
                           std::vector<Player*> players,
                           Bank* bank)
{
}