#include "player.h"

#include "bank.h"
#include "dice_base.h"

Player::Player(const std::string& name, std::shared_ptr<DiceBase> dice)
    : name_(name)
    , dice_(dice)
{
}

void Player::payCoin2Bank(Bank& bank, int coin)
{
    coin_ -= coin;
    bank.gainCoin(coin);
}

bool Player::gainCoinFromBank(std::shared_ptr<Bank> bank, int coin)
{
    if (!bank) return false;
    coin_ += coin;
    bank->payCoin(coin);
    return true;
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