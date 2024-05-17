#ifndef AMUSEMENTPARK_H
#define AMUSEMENTPARK_H

#include "landmark.h"

class AmusementPark : public Landmark {
public:
    AmusementPark();

    ~AmusementPark() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif