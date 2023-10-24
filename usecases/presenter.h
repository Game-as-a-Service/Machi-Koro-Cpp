#pragma once

#include "../models/machikoro_game.h"

class Presenter {
public:
    virtual void Present(const MachiKoroGame& game) = 0;
};
