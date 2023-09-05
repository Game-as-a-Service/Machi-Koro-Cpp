#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>

#include "dice.h"
#include "hand.h"
#include "card/landmark.h"
#include "card/building.h"

class Card;
class Landmark;
class Building;
class Hand;

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

    void PayCoin2AnotherPlayer(int coin, Player* other);

    void GainLandmarks(std::vector<std::unique_ptr<Landmark>>&& cards);

    void GainInitialBuildings(std::vector<std::unique_ptr<Building>>&& cards);

    void GainBuildingCard(std::unique_ptr<Building>&& card);

    int get_coin() const { return coin_; }

    void set_name(const std::string& name) { name_ = name; }
    std::string get_name() const { return name_; }

    const Hand* get_hand() const { return hand_.get(); }

private:
    int coin_ = 0;
    std::string name_;
    std::vector<Dice> dices_;
    std::unique_ptr<Hand> hand_ = nullptr;
};

#endif