#include "startGameController.h"

#include <iostream>

#include "../models/game_repository.h"
#include "../models/machikoro_game.h"

// Add definition of your processing function here
void StartGame::startGame(const HttpRequestPtr &req,
                 std::function<void (const HttpResponsePtr &)> &&callback){
    std::cout << "receive startGame request" << std::endl;
    
    std::string game_id;
    auto game = GameRepository::self().CreateGame(game_id);
    game->GameStart();

    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
