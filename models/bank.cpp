#include "bank.h"

Bank::Bank()
{

}

Bank::Bank(const Bank& bank)
{

}

Bank::Bank(Bank&& bank)
{

}

Bank::~Bank()
{
    
}

Bank& Bank::operator = (const Bank& rhs)
{
    return *this;
}

Bank& Bank::operator = (Bank&& rhs)
{
    return *this;
}

void Bank::PayCoin2Player(int coin, Player* player)
{
    coin_ -= coin;
    player->GainCoin(coin);
}