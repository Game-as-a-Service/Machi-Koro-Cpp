#ifndef BUSINESSCENTER_H
#define BUSINESSCENTER_H

#include "building.h"

class BusinessCenter : public Building {
public:
    BusinessCenter();

    ~BusinessCenter() = default;

    void doOperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif