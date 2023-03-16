#pragma once

#include <map>
#include <string>
#include <memory>

#include "machikoro_game.h"

class GameRepository {
public:
    GameRepository(const GameRepository& repo) = delete;
    GameRepository(GameRepository&& repo) = delete;
    ~GameRepository();

    GameRepository& operator=(const GameRepository& repo) = delete;
    GameRepository& operator=(GameRepository&& repo) = delete;

<<<<<<< HEAD
    static GameRepository& self();

    std::shared_ptr<MachiKoroGame> CreateGame(std::string& id);
=======
    static std::shared_ptr<GameRepository> self();

    std::shared_ptr<MachiKoroGame> CreateGame();
    std::shared_ptr<MachiKoroGame> CreateGame(const std::string& id);
>>>>>>> origin/test/startGame

    std::shared_ptr<MachiKoroGame> FindGameByID(const std::string& id);

private:
    GameRepository() = default;

    std::string RandomID();

    bool IsGameExist(const std::string& id);

private:
<<<<<<< HEAD
=======
    static std::shared_ptr<GameRepository> self_;
>>>>>>> origin/test/startGame
    std::map<std::string, std::shared_ptr<MachiKoroGame>> games_;
};