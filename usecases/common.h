#pragma once

#include <string>
#include <memory>
#include "../models/machikoro_game.h"
#include <json/json.h>

class Output {
public:
    void BuildGameStatus(std::shared_ptr<MachiKoroGame> game);
    std::string toJson();

private:
    Json::Value gameStatus;
};