#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "landmark.h"

class TrainStation : public Landmark {
public:
    TrainStation();

    ~TrainStation() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif