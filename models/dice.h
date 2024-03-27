#ifndef MODELS_DICE_H
#define MODELS_DICE_H

#include "dice_base.h"

class Dice : public DiceBase {
public:
    int roll() const override;
};

#endif  // MODELS_DICE_H