#ifndef WHEATFIELD_H
#define WHEATFIELD_H

#include "building.h"

class WheatField : public Building {
public:
    WheatField();
    ~WheatField() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;
    
};

#endif