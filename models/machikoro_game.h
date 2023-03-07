#ifndef MACHIKORO_GAME_H
#define MACHIKORO_GAME_H

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



private:
    std::shared_ptr<Bank> bank_ = nullptr;
    std::vector<std::shared_ptr<Player>> players_;
};

#endif