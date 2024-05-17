#ifndef CAFE_H
#define CAFE_H

#include "building.h"

class Cafe : public Building {
public:
    Cafe();

    ~Cafe() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif