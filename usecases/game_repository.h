#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "../models/machikoro_game.h"

class GameRepository {
public:
    GameRepository(const GameRepository& repo) = delete;
    GameRepository(GameRepository&& repo) = delete;
    ~GameRepository();

    GameRepository& operator=(const GameRepository& repo) = delete;
    GameRepository& operator=(GameRepository&& repo) = delete;

    static GameRepository& self();

    void AddGame(std::shared_ptr<MachiKoroGame> game);

    MachiKoroGame* FindGameByID(const std::string& id);

    void ClearAllGames();

private:
    GameRepository() = default;

    std::string RandomID();

    bool IsGameExist(const std::string& id);

private:
    std::map<std::string, std::shared_ptr<MachiKoroGame>> games_;
};