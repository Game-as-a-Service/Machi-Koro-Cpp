#ifndef APPLEORCHARD_H
#define APPLEORCHARD_H

#include "building.h"

class AppleOrchard : public Building {
public:
    AppleOrchard();
    ~AppleOrchard() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif