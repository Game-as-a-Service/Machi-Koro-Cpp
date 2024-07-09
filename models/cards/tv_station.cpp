#include "tv_station.h"

#include "models/bank.h"
#include "models/player.h"

TvStation::TvStation()
    : Building(CardName::TV_STATION,
               CardType::MAJOR_ESTABLISHMENT,
               7,
               IndustryType::PRIMARY_INDUSTRY,
               { 6 })
{
}

void TvStation::doOperateEffect(Player* owner,
                              Player* dice_roller,
                              std::vector<Player*> players,
                              Bank* bank)
{
}