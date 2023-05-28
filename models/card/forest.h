#ifndef FOREST_H
#define FOREST_H

#include "building.h"

class Forest : public Building {
public:
    Forest();
    ~Forest();

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif