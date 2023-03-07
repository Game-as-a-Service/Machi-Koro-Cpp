#include "createGameController.h"

#include <iostream>

#include "../models/game_repository.h"
#include "../models/machikoro_game.h"

// Add definition of your processing function here
// TODO: deal with same gameName
void CreateGame::createGame(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback) {
    LOG_INFO << "receive createGame request";

    auto json = req->getJsonObject();
    if (!json)
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody("missing 'value' in body");
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }
    std::string gameName = (*json)["gameName"].asString();

    auto game = GameRepository::self().CreateGame(gameName); 

    if (game == nullptr) 
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody("This gameName already exists, please use another one!");
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }

    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
