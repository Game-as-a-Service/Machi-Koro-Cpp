#include "cafe.h"

#include "models/bank.h"
#include "models/player.h"

Cafe::Cafe()
    : Building(CardName::CAFE, CardType::RESTAURANT, 2, IndustryType::RESTAURANT, { 2, 3 })
{
}

void Cafe::operateEffect(Player* owner,
                         Player* dice_roller,
                         std::vector<Player*> players,
                         Bank* bank)
{
}