#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>

#include "dice.h"
#include "hand.h"

class Player {
public:
    Player();
    Player(const std::string& name);
    Player(const Player& player) = delete;
    Player(Player&& player) = delete;
    ~Player();
    
    Player& operator = (const Player& rhs) = delete;
    Player& operator = (Player&& rhs) = delete;
    
    int RollDice();

    void PayCoin(int coin);

    void GainCoin(int coin);

    void PayCoin2AnotherPlayer(int coin, const std::shared_ptr<Player>& other);

    int get_coin() const { return coin_; }

    void set_name(const std::string& name) { name_ = name; }
    std::string get_name() const { return name_; }

    void set_hand(const std::shared_ptr<Hand>& hand) { hand_ = hand; }
    std::shared_ptr<Hand> get_hand() const { return hand_; }

private:
    int coin_ = 0;
    std::string name_;
    std::vector<Dice> dices_;
    std::shared_ptr<Hand> hand_ = nullptr;
};

#endif