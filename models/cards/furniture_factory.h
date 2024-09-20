#ifndef FURNITUREFACTORY_H
#define FURNITUREFACTORY_H

#include "building.h"

class FurnitureFactory : public Building {
public:
    FurnitureFactory();

    ~FurnitureFactory() = default;

    void doOperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif