#include "tv_station.h"

TvStation::TvStation() :
    Building(CardName::TV_STATION, 7, CardType::MAJOR_ESTABLISHMENT, {6}, IndustryType::PRIMARY_INDUSTRY)
{
}

void TvStation::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}