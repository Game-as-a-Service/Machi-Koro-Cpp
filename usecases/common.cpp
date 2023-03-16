#include "common.h"
#include <json/json.h>

// TODO: Discuss the output detail.
void Output::BuildGameStatus(std::shared_ptr<Game> game) 
{
    Json::Value status;
    status["game_id"] = game->getId();
    //status["player_name"] = game->playerName;
    //status["winner"] = game->winner;

    this->gameStatus = status;
}

std::string Output::toJson() 
{
    Json::FastWriter writer;
    std::string json_str = writer.write(this->gameStatus);
    return json_str;
}