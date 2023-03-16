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
    , name_(std::move(player.get_name()))
    , hand_(std::move(player.get_hand()))
{
    player.set_hand(nullptr);
    dices_.reserve(2);
    for (int i = 0; i < 2; ++i)
        dices_.push_back(Dice());
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