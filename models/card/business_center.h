#ifndef BUSINESSCENTER_H
#define BUSINESSCENTER_H

#include "building.h"

class BusinessCenter : public Building {
public:
    BusinessCenter();
    ~BusinessCenter() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif