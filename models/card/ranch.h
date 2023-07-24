#ifndef RANCH_H
#define RANCH_H

#include "building.h"

class Ranch : public Building {
public:
    Ranch();
    ~Ranch() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif