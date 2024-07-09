#ifndef MODELS_PLAYER_H
#define MODELS_PLAYER_H

#include <string>
#include <memory>
#include <utility>
#include <vector>

#include "models/hand.h"
#include "models/cards/building.h"

class Bank;
class DiceBase;
class Player;
using PlayerPtr = std::unique_ptr<Player>;
using PlayerPtrs = std::vector<PlayerPtr>;

class Player {
public:
    Player(const std::string& name);

    // Non copyable.
    Player(const Player& other) = delete;
    Player& operator=(const Player& other) = delete;

    ~Player() = default;

    void payCoin2Bank(Bank& bank, int coin);

    void gainCoinFromBank(Bank& bank, int coin);

    void payCoin2Player(Player* other, int coin);

    void gainCoinFromPlayer(Player* other, int coin);

    void payCoin(int coin) { coin_ -= coin; }

    void gainCoin(int coin) { coin_ += coin; }

    std::string name() const { return name_; }

    int totalCoin() const { return coin_; }

    Hand& hand() { return hand_; }

    std::pair<int, int> rollDice(DiceBase& dice, int dice_count);

    /**
     * @brief Operate the effect of the card.
     * @param dice_roller The player who rolls the dice.
     * @param others The other players.
     * @param industry_type Only the cards with the same IndustryType will be operated.
     */
    void operateEffect(Player* dice_roller, std::vector<Player*> others, int dice_point, IndustryType industry_type, Bank* bank);

private:
    // Player name.
    std::string name_;

    // Coin.
    int coin_ = 0;

    // Hand.
    Hand hand_;
};

#endif  // MODELS_PLAYER_H