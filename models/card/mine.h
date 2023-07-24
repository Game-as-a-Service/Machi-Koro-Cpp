#ifndef MINE_H
#define MINE_H

#include "building.h"

class Mine : public Building {
public:
    Mine();
    ~Mine() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif