#include "player.h"

#include "bank.h"
#include "dice_base.h"

Player::Player(const std::string& name)
    : name_(name)
{
}

void Player::payCoin2Bank(Bank& bank, int coin)
{
    coin_ -= coin;
    bank.gainCoin(coin);
}

void Player::gainCoinFromBank(Bank& bank, int coin)
{
    coin_ += coin;
    bank.payCoin(coin);
}

void Player::payCoin2Player(Player* other, int coin)
{
    coin_ -= coin;
    other->gainCoin(coin);
}

void Player::gainCoinFromPlayer(Player* other, int coin)
{
    coin_ += coin;
    other->payCoin(coin);
}

std::pair<int, int> Player::rollDice(DiceBase& dice, int dice_count)
{
    //TODO(Issue #25): Add the logic to check if the player has TrainStation.
    //
    // auto it = std::find_if(
    //     hand_->get_landmarks().begin(),
    //     hand_->get_landmarks().end(),
    //     [](Landmark* landmark) {
    //         return landmark->get_name() == CardName::TRAIN_STATION &&
    //                landmark->IsActivate();
    //     }
    // );

    // If have TrainStation and want to roll 2 dice,
    // then let it roll 2 dice.
    // if (it != hand_->get_landmarks().end() && dice_count == 2)
    //     dice_count = 2;
    // else
    //     dice_count = 1;

    int pt1 = 0, pt2 = 0;
    pt1 = dice.GeneratePoint();
    if (dice_count == 2)
        pt2 = dice.GeneratePoint();

    return std::make_pair(pt1, pt2);
}