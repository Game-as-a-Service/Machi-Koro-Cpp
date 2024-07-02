#ifndef MODELS_MACHIKORO_GAME_H
#define MODELS_MACHIKORO_GAME_H

#include <memory>
#include <string>
#include <vector>

#include "architecture_market.h"
#include "bank.h"
#include "cards/building.h"
#include "dice_base.h"
#include "events/event.h"
#include "loggers/logger_base.h"
#include "player.h"
#include "utils/util_base.h"

class MachiKoroGame {
public:
    MachiKoroGame(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util);

    ~MachiKoroGame() = default;

    // Create game instance and add players.
    std::unique_ptr<Event> createGame(std::vector<PlayerPtr>&& players);

    // Init the game.
    std::unique_ptr<Event> initGame();

    std::string game_id() const { return game_id_; }

    Bank* bank() { return &bank_; }

    ArchitectureMarket* market() { return &market_; }

    PlayerPtrs* players() { return &players_; }

    void set_dice(std::unique_ptr<DiceBase>&& dice) { dice_ = std::move(dice); }

    // For testing purpose only
    void set_current_player(int current_player) { current_player_ = current_player; }

    std::unique_ptr<Event> rollDice(const std::string& player_name, int dice_count);

private:
    int getPlayerIndex(const std::string& player_name);

    // Follow the order according to the IndustryType of each card in hand
    // e.g. IndustryType::RESTAURANT (player2(p2) -> p3 -> p4 -> p1) ->
    //      IndustryType::SECONDARY_INDUSTRY (p2 -> p3 -> p4 -> p1) ->
    //      IndustryType::PRIMARY_INDUSTRY (p2 -> p3 -> p4 -> p1) ->
    //      IndustryType::IMPORTANT_BUILDING (p2 -> p3 -> p4 -> p1)
    void operateEffect(int dice_point);

    // Logger.
    std::shared_ptr<LoggerBase> log_ = nullptr;

    // Utility.
    std::shared_ptr<UtilBase> util_ = nullptr;

    // Game ID.
    std::string game_id_;

    // Bank.
    Bank bank_;

    // Architecture Market.
    ArchitectureMarket market_;

    // Players.
    PlayerPtrs players_;

    // Current player order.
    // Mod by the number of players to know
    // the players currently playing that round.
    int current_player_ = 0;

    std::unique_ptr<DiceBase> dice_ = nullptr;
};

#endif  // MODELS_MACHIKORO_GAME_H