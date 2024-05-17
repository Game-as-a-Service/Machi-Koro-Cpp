#ifndef FRUITANDVEGETABLEMARKET_H
#define FRUITANDVEGETABLEMARKET_H

#include "building.h"

class FruitAndVegetableMarket : public Building {
public:
    FruitAndVegetableMarket();

    ~FruitAndVegetableMarket() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif