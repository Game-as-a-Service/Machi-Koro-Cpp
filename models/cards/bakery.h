#ifndef BAKERY_H
#define BAKERY_H

#include "building.h"

class Bakery : public Building {
public:
    Bakery();

    ~Bakery() = default;

    void doOperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif