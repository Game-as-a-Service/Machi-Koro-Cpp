#ifndef RADIOTOWER_H
#define RADIOTOWER_H

#include "landmark.h"

class RadioTower : public Landmark {
public:
    RadioTower();

    ~RadioTower() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif