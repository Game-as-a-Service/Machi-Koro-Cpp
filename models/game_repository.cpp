#include "game_repository.h"

#include <ctime>
#include <random>
#include <climits>
#include <algorithm>

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

std::shared_ptr<MachiKoroGame> GameRepository::CreateGame(std::string& id)
{
    if (this->IsGameExist(id)) return nullptr;
    while (id.empty() || this->IsGameExist(id)) id = this->RandomID(); 
    std::shared_ptr<MachiKoroGame> game = std::make_shared<MachiKoroGame>();
    games_.insert(std::make_pair(id, game));
    return game;
}

std::shared_ptr<MachiKoroGame> GameRepository::FindGameByID(const std::string& id)
{
    if (!this->IsGameExist(id)) return nullptr;
    return games_[id];
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