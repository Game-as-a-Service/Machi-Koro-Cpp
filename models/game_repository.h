#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "machikoro_game.h"

class GameRepository {
public:
    GameRepository(const GameRepository& repo) = delete;
    GameRepository(GameRepository&& repo) = delete;
    ~GameRepository();

    GameRepository& operator=(const GameRepository& repo) = delete;
    GameRepository& operator=(GameRepository&& repo) = delete;

    static GameRepository& self();

    std::shared_ptr<MachiKoroGame> CreateGame(const std::vector<std::string>& names);

    std::shared_ptr<MachiKoroGame> FindGameByID(const std::string& id);

    void ClearAllGames();

private:
    GameRepository() = default;

    std::string RandomID();

    bool IsGameExist(const std::string& id);

private:
    static std::shared_ptr<GameRepository> self_;
    std::map<std::string, std::shared_ptr<MachiKoroGame>> games_;
};