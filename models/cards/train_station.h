#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "landmark.h"

class TrainStation : public Landmark {
public:
    TrainStation();

    ~TrainStation() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif