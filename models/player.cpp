#include "player.h"

Player::Player()
    : hand_(std::make_unique<Hand>())
{
    dices_.reserve(2);
    for (int i = 0; i < 2; ++i)
        dices_.push_back(Dice());
}

Player::Player(const std::string& name)
    : name_(name)
    , hand_(std::make_unique<Hand>())
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

void Player::PayCoin2AnotherPlayer(int coin, Player* other)
{
    this->PayCoin(coin);
    other->GainCoin(coin);
}

void Player::GainLandmarks(std::vector<std::unique_ptr<Card>>&& cards)
{
    for (auto& card : cards)
        hand_->AddLandmark(std::move(card));
}

void Player::GainInitialBuildings(std::vector<std::unique_ptr<Card>>&& cards)
{
    for (auto& card : cards)
        hand_->AddCard(std::move(card));
}