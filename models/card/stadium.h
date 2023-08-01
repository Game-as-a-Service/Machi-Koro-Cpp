#ifndef STADIUM_H
#define STADIUM_H

#include "building.h"

class Stadium : public Building {
public:
    Stadium();
    ~Stadium() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif