#ifndef REPOS_MEMORY_REPOSITORY_H
#define REPOS_MEMORY_REPOSITORY_H

#include <string>
#include <map>
#include <memory>
#include <mutex>

#include "repos/repository.h"

// Because Drogon's design in Controller will result in multiple Controller class,
// 'MemoryRepository' is designed using Singleton Pattern.
class MemoryRepository : public Repository {
public:
    MemoryRepository(const MemoryRepository&) = delete;

    MemoryRepository& operator=(const MemoryRepository&) = delete;

    static MemoryRepository& self();

    MachiKoroGame* findById(const std::string& id) override;

    void save(std::unique_ptr<MachiKoroGame> game) override;

    void clear(const std::string& id) override;

    void clearAll();

private:
    MemoryRepository() = default;

private:
    // The mutex for 'find game'.
    std::mutex games_mutex_;

    // All the games.
    std::map<std::string, std::unique_ptr<MachiKoroGame>> games_;
};

#endif  // REPOS_MEMORY_REPOSITORY_H