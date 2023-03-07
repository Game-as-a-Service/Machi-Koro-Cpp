#include "addPlayerController.h"

#include <iostream>

#include "../models/game_repository.h"
#include "../models/machikoro_game.h"

// Add definition of your processing function here
void AddPlayer::addPlayer(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback) {
    std::cout << "receive addPlayer request" << std::endl;
    
    auto json = req->getJsonObject();
    if (!json)
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody("missing 'value' in body");
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }
    std::string playerName = (*json)["playerName"].asString();

    /*
    auto game = GameRepository::self().CreateGame(1111111111);
    game->GameStart();

    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
    */
}
