#ifndef FRUITANDVEGETABLEMARKET_H
#define FRUITANDVEGETABLEMARKET_H

#include "building.h"

class FruitAndVegetableMarket: public Building {
public:
    FruitAndVegetableMarket();
    ~FruitAndVegetableMarket() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif