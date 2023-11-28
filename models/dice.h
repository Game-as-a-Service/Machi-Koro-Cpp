#ifndef DICE_H
#define DICE_H

class Dice {
public:
    Dice() = default;
    ~Dice() = default;

    virtual int GeneratePoint() const = 0;
};

#endif