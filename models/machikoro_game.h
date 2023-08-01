#ifndef MACHIKORO_GAME_H
#define MACHIKORO_GAME_H

#include <string>
#include <vector>
#include <memory>

#include "bank.h"
#include "player.h"
#include "architecture_market.h"

class MachiKoroGame {
public:
    MachiKoroGame() = default;
    MachiKoroGame(const std::vector<std::string>& player_names);
    MachiKoroGame(const MachiKoroGame& game) = delete;
    MachiKoroGame(MachiKoroGame&& game) = delete;
    ~MachiKoroGame();
    
    MachiKoroGame& operator = (const MachiKoroGame& rhs) = delete;
    MachiKoroGame& operator = (MachiKoroGame&& rhs) = delete;

    void GameStart();

    void set_game_id(const std::string& id) { game_id_ = id; }
    std::string get_game_id() const { return game_id_; }

    std::shared_ptr<Bank> get_bank() const { return bank_; }

    std::shared_ptr<ArchitectureMarket> get_market() const { return market_; }

    std::vector<std::shared_ptr<Player>> get_players() const { return players_; }

private:
    std::string game_id_;
    std::shared_ptr<Bank> bank_ = nullptr;
    std::vector<std::shared_ptr<Player>> players_;
    std::shared_ptr<ArchitectureMarket> market_ = nullptr;
};

#endif