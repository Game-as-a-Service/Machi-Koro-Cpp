#include "player.h"

Player::Player()
{
    dices_.reserve(2);
    for (int i = 0; i < 2; ++i)
        dices_.push_back(Dice());
}

Player::Player(const std::string& name)
    : name_(name)
{
    dices_.reserve(2);
    for (int i = 0; i < 2; ++i)
        dices_.push_back(Dice());
}

Player::~Player()
{
    hand_ = nullptr;
}

int Player::RollDice()
{
    // TODO: modify this
    return 0;
}

void Player::PayCoin(int coin)
{
    coin_ -= coin;
}

void Player::GainCoin(int coin)
{
    coin_ += coin;
}

void Player::PayCoin2AnotherPlayer(int coin, const std::shared_ptr<Player>& other)
{
    this->PayCoin(coin);
    other->GainCoin(coin);
}