#include "train_station.h"

#include "models/bank.h"
#include "models/player.h"

TrainStation::TrainStation()
    : Landmark(CardName::TRAIN_STATION, CardType::MAJOR_ESTABLISHMENT, 4)
{
}

void TrainStation::OperateEffect(Player* owner,
                                 Player* dice_roller,
                                 std::vector<Player*> players,
                                 std::shared_ptr<Bank> bank)
{
}