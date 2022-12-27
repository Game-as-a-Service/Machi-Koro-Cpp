#ifndef MACHIKORO_GAME_H
#define MACHIKORO_GAME_H

#include <iostream>

// TODO : Copy constructor, Copy assignment.
// Move constructor, Move assignment.
class MachiKoroGame {
public:
    MachiKoroGame();
    ~MachiKoroGame();
    
    bool DummyTest()
    {
        std::cout << "MachiKoroGame::DummyTest()" << std::endl;
        return true;
    }

};

#endif

