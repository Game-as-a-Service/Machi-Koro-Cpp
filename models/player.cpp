#include "player.h"

Player::Player(const std::string& name, std::shared_ptr<DiceBase> dice)
    : name_(name)
    , dice_(dice)
{
}