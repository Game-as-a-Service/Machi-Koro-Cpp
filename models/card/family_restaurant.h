#ifndef FAMILYRESTAURANT_H
#define FAMILYRESTAURANT_H

#include "building.h"

class FamilyRestaurant : public Building {
public:
    FamilyRestaurant();
    ~FamilyRestaurant() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif