#include "player.h"

Player::Player(const std::string& name, std::shared_ptr<Dice> dice)
    : name_(name)
    , dice_(dice)
{
}