#ifndef MODELS_PLAYER_H
#define MODELS_PLAYER_H

#include <string>
#include <memory>
#include <iostream>

#include "dice_base.h"

class Player {
public:
    Player(const std::string& name, std::shared_ptr<DiceBase> dice);

    ~Player() = default;

    std::string name() const { return name_; }

private:
    // Player name.
    std::string name_;

    // Coin.
    int coin_ = 0;

    // Dice.
    std::shared_ptr<DiceBase> dice_ = nullptr;
};

#endif  // MODELS_PLAYER_H