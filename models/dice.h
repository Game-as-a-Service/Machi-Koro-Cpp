#ifndef MODELS_DICE_H
#define MODELS_DICE_H

#include <random>

#include "dice_base.h"

class Dice : public DiceBase {
public:
    ~Dice() override = default;

    int generatePoint() const final;
private:
    mutable std::mt19937 generator_{std::random_device{}()};
    mutable std::uniform_int_distribution<int> unif_{1, 6};
};

#endif  // MODELS_DICE_H