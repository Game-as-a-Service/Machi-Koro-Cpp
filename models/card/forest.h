#ifndef FOREST_H
#define FOREST_H

#include "building.h"

class Forest : public Building {
public:
    Forest();
    ~Forest() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif