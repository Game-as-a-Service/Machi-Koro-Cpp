#ifndef APPLEORCHARD_H
#define APPLEORCHARD_H

#include "building.h"

class AppleOrchard : public Building {
public:
    AppleOrchard();
    ~AppleOrchard() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif