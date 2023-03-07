#include "player.h"

Player::Player()
{
    dices_.reserve(2);
    for (int i = 0; i < 2; ++i)
        dices_.push_back(Dice());
}

Player::Player(const Player& player)
    : coin_(player.get_coin())
    , name_(player.get_name())
    , hand_(player.get_hand())
{
    dices_.reserve(2);
    for (int i = 0; i < 2; ++i)
        dices_.push_back(Dice());
}

Player::Player(Player&& player)
    : coin_(std::move(player.get_coin()))
{

}

Player::~Player()
{

}

Player& Player::operator = (const Player& rhs)
{
    return *this;
}

Player& Player::operator = (Player&& rhs)
{
    return *this;
}

int Player::RollDice()
{

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