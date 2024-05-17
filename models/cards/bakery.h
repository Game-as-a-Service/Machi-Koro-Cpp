#ifndef BAKERY_H
#define BAKERY_H

#include "building.h"

class Bakery : public Building {
public:
    Bakery();

    ~Bakery() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif