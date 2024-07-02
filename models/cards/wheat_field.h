#ifndef WHEATFIELD_H
#define WHEATFIELD_H

#include "building.h"

class WheatField : public Building {
public:
    WheatField();

    ~WheatField() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif