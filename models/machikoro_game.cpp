#include "machikoro_game.h"

#include <iostream>

MachiKoroGame::MachiKoroGame(const std::vector<std::string>& player_names)
{
    for (const auto& name : player_names)
    {
        auto player = std::make_shared<Player>(name);
        players_.push_back(player);
    }
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