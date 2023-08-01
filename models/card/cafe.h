#ifndef CAFE_H
#define CAFE_H

#include "building.h"

class Cafe : public Building {
public:
    Cafe();
    ~Cafe() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif