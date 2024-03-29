#include "apple_orchard.h"

#include "models/bank.h"
#include "models/player.h"

AppleOrchard::AppleOrchard()
    : Building(CardName::APPLE_ORCHARD, CardType::CROP, 3, IndustryType::PRIMARY_INDUSTRY, { 10 })
{
}

void AppleOrchard::OperateEffect(Player* owner,
                                 Player* dice_roller,
                                 std::vector<Player*> players,
                                 Bank* bank)
{
}