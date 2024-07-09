#include "train_station.h"

#include "models/bank.h"
#include "models/player.h"

TrainStation::TrainStation()
    : Landmark(CardName::TRAIN_STATION, CardType::MAJOR_ESTABLISHMENT, 4)
{
}

void TrainStation::operateEffect(Player* owner,
                       Player* dice_roller,
                       int point,
                       std::vector<Player*> players,
                       Bank* bank,
                       IndustryType curr_industry_type)
{
}