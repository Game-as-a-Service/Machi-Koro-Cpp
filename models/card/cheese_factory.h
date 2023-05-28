#ifndef CHEESEFACTORY_H
#define CHEESEFACTORY_H

#include "building.h"

class CheeseFactory : public Building {
public:
    CheeseFactory();
    ~CheeseFactory() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif