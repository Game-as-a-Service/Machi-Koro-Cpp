#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class CreateGame : public drogon::HttpController<CreateGame>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(CreateGame::createGame, "/createGame", Post);
    METHOD_LIST_END
    
    void createGame(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback);
};
