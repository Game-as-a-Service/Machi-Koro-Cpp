#ifndef BUSINESSCENTER_H
#define BUSINESSCENTER_H

#include "building.h"

class BusinessCenter : public Building {
public:
    BusinessCenter();
    ~BusinessCenter() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif