#ifndef RANCH_H
#define RANCH_H

#include "building.h"

class Ranch : public Building {
public:
    Ranch();

    ~Ranch() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif