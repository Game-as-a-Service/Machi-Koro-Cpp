#ifndef MODELS_MACHIKORO_GAME_H
#define MODELS_MACHIKORO_GAME_H

#include <memory>
#include <string>
#include <vector>

#include "utils/util_base.h"
#include "loggers/logger_base.h"
#include "events/event.h"
#include "player.h"

class MachiKoroGame {
public:
    MachiKoroGame(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util);

    ~MachiKoroGame() = default;

    // Create game instance and add players.
    std::unique_ptr<Event> createGame(std::vector<Player>&& players);

    std::string game_id() const { return game_id_; }

private:
    // Logger.
    std::shared_ptr<LoggerBase> log_ = nullptr;

    // Utility.
    std::shared_ptr<UtilBase> util_ = nullptr;

    // Game ID.
    std::string game_id_;

    // Players.
    std::vector<Player> players_;
};

#endif  // MODELS_MACHIKORO_GAME_H