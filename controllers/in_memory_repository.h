#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "../models/machikoro_game.h"
#include "../usecases/game_repository.h"

class InMemoryRepository : public GameRepository {
public:
    InMemoryRepository(const InMemoryRepository& repo) = delete;
    InMemoryRepository(InMemoryRepository&& repo) = delete;
    ~InMemoryRepository();

    InMemoryRepository& operator=(const InMemoryRepository& repo) = delete;
    InMemoryRepository& operator=(InMemoryRepository&& repo) = delete;

    static InMemoryRepository& self();

    void AddGame(std::shared_ptr<MachiKoroGame> game) override;
    
    void SaveGame(std::shared_ptr<MachiKoroGame> game) override;

    MachiKoroGame* FindGameByID(const std::string& id) override;

    void ClearAllGames() override;

private:
    InMemoryRepository() = default;

    std::string RandomID();

    bool IsGameExist(const std::string& id);

private:
    std::map<std::string, std::shared_ptr<MachiKoroGame>> games_;
};