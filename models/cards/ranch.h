#ifndef RANCH_H
#define RANCH_H

#include "building.h"

class Ranch : public Building {
public:
    Ranch();

    ~Ranch() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif