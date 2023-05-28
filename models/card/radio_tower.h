#ifndef RADIOTOWER_H
#define RADIOTOWER_H

#include "landmark.h"

class RadioTower : public Landmark {
public:
    RadioTower();
    ~RadioTower() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif