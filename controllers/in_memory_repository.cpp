#include "in_memory_repository.h"

#include <ctime>
#include <random>
#include <climits>
#include <algorithm>
#include <iostream>

InMemoryRepository::~InMemoryRepository()
{
    games_.clear();
}

InMemoryRepository& InMemoryRepository::self()
{
    static InMemoryRepository repo;
    return repo;
}

void InMemoryRepository::AddGame(std::shared_ptr<MachiKoroGame> game)
{
    std::string id = this->RandomID();
    while (this->IsGameExist(id)) 
        id = this->RandomID();
    game->set_game_id(id);
    games_[id] = game;
}

void InMemoryRepository::SaveGame(std::shared_ptr<MachiKoroGame> game)
{
    return;
}

MachiKoroGame* InMemoryRepository::FindGameByID(const std::string& id)
{
    if (!this->IsGameExist(id)) return nullptr;
    return games_[id].get();
}

void InMemoryRepository::ClearAllGames()
{
    for (auto& game : games_)
        game.second.reset();
    games_.clear();
}

bool InMemoryRepository::IsGameExist(const std::string& id)
{
    return (games_.find(id) != games_.end());
}

std::string InMemoryRepository::RandomID()
{
    std::uniform_int_distribution<int> u(0, INT_MAX);
    std::default_random_engine e(time(0));
    std::string id = std::to_string(u(e));
    return id;
}