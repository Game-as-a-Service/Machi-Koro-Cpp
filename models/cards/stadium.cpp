#include "stadium.h"

#include "models/bank.h"
#include "models/player.h"

Stadium::Stadium()
    : Building(CardName::STADIUM,
               CardType::MAJOR_ESTABLISHMENT,
               6,
               IndustryType::IMPORTANT_BUILDING,
               { 6 })
{
}

void Stadium::doOperateEffect(Player* owner,
                            Player* dice_roller,
                            std::vector<Player*> players,
                            Bank* bank)
{
}