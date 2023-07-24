#ifndef BAKERY_H
#define BAKERY_H

#include "building.h"

class Bakery : public Building {
public:
    Bakery();
    ~Bakery() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif