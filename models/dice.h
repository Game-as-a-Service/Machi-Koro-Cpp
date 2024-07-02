#ifndef MODELS_DICE_H
#define MODELS_DICE_H

#include "dice_base.h"

class Dice : public DiceBase {
public:
    ~Dice() override = default;

    int generatePoint() const final;
};

#endif  // MODELS_DICE_H