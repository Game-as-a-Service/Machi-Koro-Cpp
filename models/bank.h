#ifndef BANK_H
#define BANK_H

#include "player.h"

class Player;

class Bank {
public:
    Bank();
    Bank(const Bank& bank);
    Bank(Bank&& bank);
    ~Bank();

    Bank& operator = (const Bank& rhs);
    Bank& operator = (Bank&& rhs);

    void PayCoin2Player(int coin, const std::shared_ptr<Player>& player);

    int get_coin() const { return coin_; } 
    
private:
    int coin_ = 282;
};

#endif