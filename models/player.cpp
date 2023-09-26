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

int Player::RollDice(int dice_count)
{
    auto it = std::find(
        hand_->get_landmarks().begin(), 
        hand_->get_landmarks().end(),
        [&](const auto& landmark) {
            return landmark->get_name() == CardName::TRAIN_STATION &&
                landmark->IsActivate();
        }
    );

    // If have TrainStation and want to roll 2 dice,
    // then let it roll 2 dice.
    if (it != hand_->get_landmarks().end() && dice_count == 2)
        dice_count = 2;
    else
        dice_count = 1;

    // TODO: 可以擲兩顆且兩顆點數一樣的時候，有權利馬上再進行一回合
    int res = 0;
    for (int i = 0; i < dice_count; ++i)
        res += dices_[i].GeneratePoint();

    return res;
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

void Player::GainLandmarks(std::vector<std::unique_ptr<Landmark>>&& cards)
{
    for (auto& card : cards)
        hand_->AddLandmark(std::move(card));
}

void Player::GainInitialBuildings(std::vector<std::unique_ptr<Building>>&& cards)
{
    for (auto& card : cards)
        hand_->AddBuilding(std::move(card));
}

void Player::GainBuildingCard(std::unique_ptr<Building>&& card)
{
    hand_->AddBuilding(std::move(card));
}