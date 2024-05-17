#ifndef APPLEORCHARD_H
#define APPLEORCHARD_H

#include "building.h"

class AppleOrchard : public Building {
public:
    AppleOrchard();

    ~AppleOrchard() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif