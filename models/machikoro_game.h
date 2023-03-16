#ifndef MACHIKORO_GAME_H
#define MACHIKORO_GAME_H

#include <string>
#include <vector>
#include <memory>

#include "bank.h"
#include "player.h"

class MachiKoroGame {
public:
    MachiKoroGame();
    MachiKoroGame(const MachiKoroGame& game);
    MachiKoroGame(MachiKoroGame&& game);
    ~MachiKoroGame();
    
    MachiKoroGame& operator = (const MachiKoroGame& rhs);
    MachiKoroGame& operator = (MachiKoroGame&& rhs);

    bool AddPlayer(const std::shared_ptr<Player>& player);

    void GameStart();

    void set_game_id(const std::string& id) { game_id_ = id; }
    std::string get_game_id() const { return game_id_; }

private:
    std::string game_id_;
    std::shared_ptr<Bank> bank_ = nullptr;
    std::vector<std::shared_ptr<Player>> players_;
};

#endif