#pragma once

#include <string>
#include <memory>
#include "../models/machikoro_game.h"
#include <json/json.h>

class Output {
public:
    void BuildGameStatus(std::shared_ptr<MachiKoroGame> game);
    std::string toJson();
    std::string get_game_id() const { return gameStatus["game_id"].asString(); }

private:
    Json::Value gameStatus;
};