#ifndef RADIOTOWER_H
#define RADIOTOWER_H

#include "landmark.h"

class RadioTower : public Landmark {
public:
    RadioTower();
    ~RadioTower() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif