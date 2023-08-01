#include "train_station.h"

TrainStation::TrainStation() : 
    Landmark(CardName::TRAIN_STATION, 4, CardType::MAJOR_ESTABLISHMENT)
{
}

void TrainStation::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}