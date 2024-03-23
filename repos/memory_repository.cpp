#include "repos/memory_repository.h"

#include <mutex>

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

void MemoryRepository::clear(const std::string& id)
{
    std::lock_guard<std::mutex> lock(games_mutex_);
    if (games_.find(id) == games_.end()) return;
    games_.erase(id);
}

void MemoryRepository::clearAll()
{
    std::lock_guard<std::mutex> lock(games_mutex_);
    games_.clear();
}