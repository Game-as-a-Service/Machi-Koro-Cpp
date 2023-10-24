#ifndef DICE_H
#define DICE_H

class Dice {
public:
    Dice() = default;
    ~Dice() = default;
    
    int GeneratePoint() const;
};

#endif