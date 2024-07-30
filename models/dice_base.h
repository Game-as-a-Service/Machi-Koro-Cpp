#ifndef MODELS_DICE_BASE_H
#define MODELS_DICE_BASE_H

class DiceBase {
public:
    virtual ~DiceBase() = default;

    // Let dice generate the points.
    virtual int generatePoint() const = 0;
};

#endif  // MODELS_DICE_BASE_H