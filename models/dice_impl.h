#ifndef DICE_IMPL_H
#define DICE_IMPL_H

#include "dice.h"

class DiceImpl : public Dice {
public:
    DiceImpl() = default;
    ~DiceImpl() = default;

    int GeneratePoint() const final;
};

#endif