#ifndef REPOS_MEMORY_REPOSITORY_H
#define REPOS_MEMORY_REPOSITORY_H

#include <string>
#include <map>
#include <memory>
#include <mutex>

#include "loggers/logger.h"
#include "repos/repository.h"
#include "utils/util.h"

class LoggerBase;
class MachiKoroGame;
class Presenter;
class UtilBase;

// Because Drogon's design in Controller will result in multiple Controller class,
// 'MemoryRepository' is designed using Singleton Pattern.
class MemoryRepository : public Repository {
public:
    MemoryRepository(const MemoryRepository&) = delete;

    MemoryRepository& operator=(const MemoryRepository&) = delete;

    static MemoryRepository& self();

    MachiKoroGame* findById(const std::string& id) override;

    void save(std::unique_ptr<MachiKoroGame> game) override;

    bool clear_game(const std::string& id) override;

    size_t game_num() override;

    void clearAll();

private:
    MemoryRepository() = default;

private:
    // Logger.
    std::shared_ptr<LoggerBase> log_ = Logger::self();

    // Utility.
    std::shared_ptr<UtilBase> util_ = Util::self();

    // The mutex for 'find game'.
    std::mutex games_mutex_;

    // All the games.
    std::map<std::string, std::unique_ptr<MachiKoroGame>> games_;
};

#endif  // REPOS_MEMORY_REPOSITORY_H