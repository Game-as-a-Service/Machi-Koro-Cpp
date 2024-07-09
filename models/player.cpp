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
    int pt1 = 0, pt2 = 0;
    pt1 = dice.generatePoint();
    if (dice_count == 2)
        pt2 = dice.generatePoint();

    return std::make_pair(pt1, pt2);
}

void Player::operateEffect(Player* dice_roller, std::vector<Player*> players, int dice_point, IndustryType industry_type, Bank* bank) {
    // Follow the order according to the IndustryType of each card in hand
    auto buildings = hand_.buildings();
    for (auto building : buildings) {
        building->operateEffect(this, dice_roller, dice_point, players, bank, industry_type);
    }
}