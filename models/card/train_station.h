#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "landmark.h"

class TrainStation : public Landmark{
public:
    TrainStation();
    ~TrainStation() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif