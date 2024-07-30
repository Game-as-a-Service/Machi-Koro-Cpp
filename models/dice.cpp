#include "dice.h"

int Dice::generatePoint() const
{
    return unif_(generator_);
}
