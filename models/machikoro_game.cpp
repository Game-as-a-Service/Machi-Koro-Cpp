#include "machikoro_game.h"
#include <iostream>

MachiKoroGame::MachiKoroGame() 
{
}

MachiKoroGame::~MachiKoroGame()
{
}

bool MachiKoroGame::AddPlayer(const std::shared_ptr<Player>& player)
{
    if (players_.size() >= 4) return false;
    players_.push_back(player);
    return true;
}

void MachiKoroGame::GameStart()
{
    std::cout << "Game Start !!" << std::endl;
}