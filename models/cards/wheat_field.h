#ifndef WHEATFIELD_H
#define WHEATFIELD_H

#include "building.h"

class WheatField : public Building {
public:
    WheatField();

    ~WheatField() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif