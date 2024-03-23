#ifndef MODELS_DICE_IMPL_H
#define MODELS_DICE_IMPL_H

#include "dice.h"

class DiceImpl : public Dice {
public:
    DiceImpl() = default;

    ~DiceImpl() = default;

    int roll() const override;
};

#endif  // MODELS_DICE_IMPL_H