#include "machikoro_game.h"

#include <iostream>

MachiKoroGame::MachiKoroGame(const std::vector<std::string>& player_names)
{
    for (const auto& name : player_names)
    {
        auto player = std::make_shared<Player>(name);
        players_.push_back(player);
    }
    
    bank_ = std::make_shared<Bank>();
    for (auto& player : players_)
        bank_->PayCoin2Player(3, player);

    market_ = std::make_shared<ArchitectureMarket>();
    // Create 84 Architecture Cards.(12 important _building, 72 building)
    // 8 initial_buildings, 16 landmarks

    // Player draw cards.
    // market_ gives 2 initial buildings to each player
    // market_ gives 4 landmarks to each player(backside)
    

    // Choose one player as starter
}

MachiKoroGame::~MachiKoroGame()
{
    bank_ = nullptr;
    for (auto& p : players_) 
        p = nullptr;
    players_.clear();
}

void MachiKoroGame::GameStart()
{
    std::cout << "Game Start !!" << std::endl;
}