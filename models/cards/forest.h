#ifndef FOREST_H
#define FOREST_H

#include "building.h"

class Forest : public Building {
public:
    Forest();

    ~Forest() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif