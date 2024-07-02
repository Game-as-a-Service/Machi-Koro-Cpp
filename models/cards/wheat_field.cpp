#include "wheat_field.h"

#include "models/bank.h"
#include "models/player.h"

WheatField::WheatField()
    : Building(CardName::WHEAT_FIELD, CardType::CROP, 1, IndustryType::PRIMARY_INDUSTRY, { 1 })
{
}

void WheatField::operateEffect(Player* owner,
                               Player* dice_roller,
                               std::vector<Player*> players,
                               Bank* bank)
{
    owner->gainCoinFromBank(*bank, 1);
}