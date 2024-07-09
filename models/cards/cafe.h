#ifndef CAFE_H
#define CAFE_H

#include "building.h"

class Cafe : public Building {
public:
    Cafe();

    ~Cafe() = default;

    void doOperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif