// TODO(issue#13): Maybe move repository to usecase layer from model
#include "game_repository.h"

#include <ctime>
#include <random>
#include <climits>
#include <algorithm>
#include <iostream>

GameRepository::~GameRepository()
{
    games_.clear();
}

GameRepository& GameRepository::self()
{
    static GameRepository repo;
    return repo;
}

void GameRepository::AddGame(std::shared_ptr<MachiKoroGame> game)
{
    std::string id = this->RandomID();
    while (this->IsGameExist(id)) 
        id = this->RandomID();
    game->set_game_id(id);
    games_[id] = game;
}

MachiKoroGame* GameRepository::FindGameByID(const std::string& id)
{
    if (!this->IsGameExist(id)) return nullptr;
    return games_[id].get();
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