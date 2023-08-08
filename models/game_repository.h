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

    // TODO: Maybe remove this function. We need to create game first, 
    // and then store it into repository.
    MachiKoroGame* CreateGame(const std::vector<std::string>& names);

    MachiKoroGame* FindGameByID(const std::string& id);

    void ClearAllGames();

private:
    GameRepository() = default;

    std::string RandomID();

    bool IsGameExist(const std::string& id);

private:
    std::map<std::string, std::unique_ptr<MachiKoroGame>> games_;
};