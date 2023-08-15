#ifndef BAKERY_H
#define BAKERY_H

#include "building.h"

class Bakery : public Building {
public:
    Bakery();
    ~Bakery() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif