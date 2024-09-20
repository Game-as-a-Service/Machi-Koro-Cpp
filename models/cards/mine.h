#ifndef MINE_H
#define MINE_H

#include "building.h"

class Mine : public Building {
public:
    Mine();

    ~Mine() = default;

    void doOperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif