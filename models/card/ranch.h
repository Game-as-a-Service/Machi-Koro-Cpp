#ifndef RANCH_H
#define RANCH_H

#include "building.h"

class Ranch : public Building {
public:
    Ranch();
    ~Ranch() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif