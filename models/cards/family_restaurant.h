#ifndef FAMILYRESTAURANT_H
#define FAMILYRESTAURANT_H

#include "building.h"

class FamilyRestaurant : public Building {
public:
    FamilyRestaurant();

    ~FamilyRestaurant() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif