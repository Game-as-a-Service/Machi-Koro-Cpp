#ifndef STADIUM_H
#define STADIUM_H

#include "building.h"

class Stadium : public Building {
public:
    Stadium();

    ~Stadium() = default;

    void doOperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif