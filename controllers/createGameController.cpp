#include "createGameController.h"

#include <iostream>

#include "../usecases/createGameUsecase.h"

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
    
    CreateGameUsecase uc;
    uc.CreateGameExecute(
        CreateGameUsecaseRequest(...),

    );

    Json::Value ret;
    ret["result"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

