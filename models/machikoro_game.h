#ifndef MACHIKORO_GAME_H
#define MACHIKORO_GAME_H

#include "player.h"
#include "card.h"
#include "bank.h"
#include "landmark.h"
#include "dice.h"

class MachiKoroGame {
public:
    MachiKoroGame();
    MachiKoroGame(const MachiKoroGame& game);
    MachiKoroGame(MachiKoroGame&& game);
    ~MachiKoroGame();
    
    MachiKoroGame& operator=(const MachiKoroGame& rhs);
    MachiKoroGame& operator=(MachiKoroGame&& rhs);

    void GameStart(); 

    Player CreatPlayer();//return 4 player
    Bank CreatBank();//initial bank
    Card CreatCank();//initial card
    Landmark CreatLankMark();//initial landmark
    Dice CreatDice();//initial dice

private:

};

#endif