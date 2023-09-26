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

    void RollDice(std::string player_id, int dice_count);

    void set_game_id(const std::string& id) { game_id_ = id; }
    std::string get_game_id() const { return game_id_; }

    const Bank* get_bank() const { return bank_.get(); }

    const ArchitectureMarket* get_market() const { return market_.get(); }

    // TODO(smart pointer): implement this function.
    std::vector<Player*> get_players();

private:
    std::string game_id_;
    std::unique_ptr<Bank> bank_ = nullptr;
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<ArchitectureMarket> market_ = nullptr;
};

#endif