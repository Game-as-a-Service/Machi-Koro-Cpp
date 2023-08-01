#ifndef STADIUM_H
#define STADIUM_H

#include "building.h"

class Stadium : public Building {
public:
    Stadium();
    ~Stadium() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif