#include "player.h"

Player::Player()
    : hand_(std::make_unique<Hand>())
{
}

Player::Player(const std::string& name)
    : name_(name)
    , hand_(std::make_unique<Hand>())
{
}

Player::~Player()
{
    hand_ = nullptr;
}

std::pair<int, int> Player::RollDice(int dice_count)
{
    auto it = std::find(
        hand_->get_landmarks().begin(), 
        hand_->get_landmarks().end(),
        [](const auto& landmark) {
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

    int pt1 = 0, pt2 = 0;
    pt1 = dice_.GeneratePoint();
    if (dice_count == 2)
        pt2 = dice_.GeneratePoint();

    return std::make_pair(pt1, pt2); 
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
        hand_->AddBuilding(std::move(card));
}
