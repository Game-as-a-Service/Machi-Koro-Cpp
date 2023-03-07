#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class StartGame : public drogon::HttpController<StartGame>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(StartGame::startGame, "/startGame", Post);
    METHOD_LIST_END
    
    void startGame(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback);
};
