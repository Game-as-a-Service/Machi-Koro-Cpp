#include "dice_impl.h"

#include <random>

int DiceImpl::roll() const
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> unif(1, 6);
    return unif(generator);
}