#include "cafe.h"

#include "models/bank.h"
#include "models/player.h"

Cafe::Cafe()
    : Building(CardName::CAFE, CardType::RESTAURANT, 2, IndustryType::RESTAURANT, { 2, 3 })
{
}

void Cafe::doOperateEffect(Player* owner,
                         Player* dice_roller,
                         std::vector<Player*> players,
                         Bank* bank)
{
}