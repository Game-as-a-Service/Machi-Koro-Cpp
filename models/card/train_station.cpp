#include "train_station.h"

TrainStation::TrainStation() : 
    Landmark(CardName::TRAIN_STATION, 4, CardType::MAJOR_ESTABLISHMENT)
{
}

void TrainStation::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}