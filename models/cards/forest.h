#ifndef FOREST_H
#define FOREST_H

#include "building.h"

class Forest : public Building {
public:
    Forest();

    ~Forest() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif