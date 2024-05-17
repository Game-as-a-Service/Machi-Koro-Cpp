#ifndef MINE_H
#define MINE_H

#include "building.h"

class Mine : public Building {
public:
    Mine();

    ~Mine() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif