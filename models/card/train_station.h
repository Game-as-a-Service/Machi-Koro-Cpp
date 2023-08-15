#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "landmark.h"

class TrainStation : public Landmark{
public:
    TrainStation();
    ~TrainStation() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif