#ifndef CAFE_H
#define CAFE_H

#include "building.h"

class Cafe : public Building {
public:
    Cafe();
    ~Cafe() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif