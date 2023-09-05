#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "../models/machikoro_game.h"

class GameRepository {
public:
    virtual ~GameRepository() = default;

    // TODO(#issue 17): use raw pointer instead.
    virtual void AddGame(std::shared_ptr<MachiKoroGame> game) = 0;
    
    // TODO(#issue 17): use raw pointer instead.
    virtual void SaveGame(std::shared_ptr<MachiKoroGame> game) = 0;

    virtual MachiKoroGame* FindGameByID(const std::string& id) = 0;

    virtual void ClearAllGames() = 0;
};