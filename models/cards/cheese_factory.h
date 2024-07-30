#ifndef CHEESEFACTORY_H
#define CHEESEFACTORY_H

#include "building.h"

class CheeseFactory : public Building {
public:
    CheeseFactory();

    ~CheeseFactory() = default;

    void doOperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif