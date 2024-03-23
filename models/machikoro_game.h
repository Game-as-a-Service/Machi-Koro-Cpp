#ifndef MODELS_MACHIKORO_GAME_H
#define MODELS_MACHIKORO_GAME_H

#include <memory>
#include <string>
#include <vector>

#include "utils/util.h"
#include "loggers/logger.h"
#include "events/event.h"
#include "player.h"

class MachiKoroGame {
public:
    MachiKoroGame(std::shared_ptr<Logger> logger, std::shared_ptr<Util> util);

    ~MachiKoroGame() = default;

    // Create game instance and add players.
    std::unique_ptr<Event> createGame(std::vector<Player>&& players);

    std::string game_id() const { return game_id_; }

private:
    // Logger.
    std::shared_ptr<Logger> log_ = nullptr;

    // Utility.
    std::shared_ptr<Util> util_ = nullptr;

    // Game ID.
    std::string game_id_;

    // Players.
    std::vector<Player> players_;
};

#endif  // MODELS_MACHIKORO_GAME_H