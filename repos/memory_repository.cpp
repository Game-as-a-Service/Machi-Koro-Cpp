#include "repos/memory_repository.h"

#include <mutex>

#include "loggers/logger.h"
#include "loggers/logger_base.h"
#include "models/machikoro_game.h"
#include "repos/repository.h"
#include "utils/util.h"
#include "utils/util_base.h"

MemoryRepository& MemoryRepository::self()
{
    static MemoryRepository repo;
    return repo;
}

MachiKoroGame* MemoryRepository::findById(const std::string& id)
{
    std::lock_guard<std::mutex> lock(games_mutex_);
    if (games_.find(id) == games_.end()) return nullptr;
    return games_[id].get();
}

void MemoryRepository::save(std::unique_ptr<MachiKoroGame> game)
{
    std::lock_guard<std::mutex> lock(games_mutex_);
    games_[game->game_id()] = std::move(game);
}

bool MemoryRepository::clear_game(const std::string& id)
{
    std::lock_guard<std::mutex> lock(games_mutex_);
    if (games_.find(id) == games_.end()) return false;
    games_.erase(id);
    return true;
}

size_t MemoryRepository::game_num()
{
    std::lock_guard<std::mutex> lock(games_mutex_);
    return games_.size();
}

void MemoryRepository::clearAll()
{
    std::lock_guard<std::mutex> lock(games_mutex_);
    games_.clear();
}