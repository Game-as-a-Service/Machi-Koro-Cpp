#include "tv_station.h"

TvStation::TvStation() : 
    Building(CardName::TV_STATION, 7, CardType::MAJOR_ESTABLISHMENT, {6}, IndustryType::PRIMARY_INDUSTRY)
{
}

void TvStation::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}