#include "game_repository.h"

#include <ctime>
#include <random>
#include <climits>
#include <algorithm>
#include <iostream>

std::shared_ptr<GameRepository> GameRepository::self_ = nullptr;

GameRepository::~GameRepository()
{
    games_.clear();
}

GameRepository& GameRepository::self()
{
    static GameRepository repo;
    return repo;
}

std::shared_ptr<MachiKoroGame> GameRepository::CreateGame(const std::vector<std::string>& names)
{
    std::string id = this->RandomID();
    while (this->IsGameExist(id)) id = this->RandomID();
    std::shared_ptr<MachiKoroGame> game = std::make_shared<MachiKoroGame>();//Create a new game instance.
    game->set_game_id(id);
    // TODO: Decide the way to new the game.
    for (const auto& name : names)
    {
        auto player = std::make_shared<Player>(name);
        if (!game->AddPlayer(player))
            std::cout << "Add player, " << name << ", failed !!" << std::endl;
    }
    return game;
}

std::shared_ptr<MachiKoroGame> GameRepository::FindGameByID(const std::string& id)
{
    if (!this->IsGameExist(id)) return nullptr;
    return games_[id];
}

void GameRepository::ClearAllGames()
{
    for (auto& game : games_)
        game.second.reset();
    games_.clear();
}

bool GameRepository::IsGameExist(const std::string& id)
{
    return (games_.find(id) != games_.end());
}

std::string GameRepository::RandomID()
{
    std::uniform_int_distribution<int> u(0, INT_MAX);
    std::default_random_engine e(time(0));
    std::string id = std::to_string(u(e));
    return id;
}