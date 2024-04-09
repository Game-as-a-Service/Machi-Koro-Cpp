#include "business_center.h"

#include "models/bank.h"
#include "models/player.h"

BusinessCenter::BusinessCenter()
    : Building(CardName::BUSINESS_CENTER,
               CardType::MAJOR_ESTABLISHMENT,
               8,
               IndustryType::IMPORTANT_BUILDING,
               { 6 })
{
}

void BusinessCenter::OperateEffect(Player* owner,
                                   Player* dice_roller,
                                   std::vector<Player*> players,
                                   Bank* bank)
{
}