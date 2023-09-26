#include "machikoro_game.h"

#include <iostream>

MachiKoroGame::MachiKoroGame(const std::vector<std::string>& player_names)
{
    for (const auto& name : player_names)
    {
        auto player = std::make_unique<Player>(name);
        players_.push_back(std::move(player));
    }

    bank_ = std::make_unique<Bank>();
    for (auto& player : players_)
        bank_->PayCoin2Player(3, player.get());

    market_ = std::make_unique<ArchitectureMarket>();

    for (auto& player : players_) {
        player->GainInitialBuildings(std::move(market_->GetInitialBuildingsForOnePlayer()));
        player->GainLandmarks(std::move(market_->GetLandmarksForOnePlayer()));
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

std::vector<const Player*> MachiKoroGame::get_players() const
{
    std::vector<const Player*> players;
    for (const auto& player: players_)
        players.push_back(player.get());
    return players;
}

void MachiKoroGame::RollDice(std::string player_id, int dice_count) {
    check player_id is current player
    int count = player->RollDice(dice_count);
    // 發動效果？

    return;
}