#ifndef STADIUM_H
#define STADIUM_H

#include "building.h"

class Stadium : public Building {
public:
    Stadium();

    ~Stadium() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif