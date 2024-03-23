#ifndef MODELS_DICE_H
#define MODELS_DICE_H

class Dice {
public:
    virtual ~Dice() = default;

    // Let dice generate the points.
    virtual int roll() const = 0;
};

#endif  // MODELS_DICE_H