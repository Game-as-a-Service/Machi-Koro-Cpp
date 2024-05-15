#ifndef MODELS_MACHIKORO_GAME_H
#define MODELS_MACHIKORO_GAME_H

#include <memory>
#include <string>
#include <vector>

#include "utils/util_base.h"
#include "loggers/logger_base.h"
#include "events/event.h"
#include "player.h"
#include "bank.h"
#include "architecture_market.h"

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

private:
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
};

#endif  // MODELS_MACHIKORO_GAME_H