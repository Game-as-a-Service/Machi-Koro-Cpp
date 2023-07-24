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
    
    for (auto& player : players_) {
        player->GainInitialBuildings(market_->GetInitialBuildingsForOnePlayer());
        player->GainLandmarks(market_->GetLandmarksForOnePlayer());
    }

    // Choose one player as starter
    
}

MachiKoroGame::~MachiKoroGame()
{
    bank_ = nullptr;
    market_ = nullptr;
    for (auto& p : players_) 
        p = nullptr;
    players_.clear();
}

void MachiKoroGame::GameStart()
{
    std::cout << "Game Start !!" << std::endl;
}