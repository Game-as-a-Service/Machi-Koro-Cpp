#ifndef FAMILYRESTAURANT_H
#define FAMILYRESTAURANT_H

#include "building.h"

class FamilyRestaurant : public Building {
public:
    FamilyRestaurant();

    ~FamilyRestaurant() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif