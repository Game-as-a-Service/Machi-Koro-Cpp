#pragma once

#include <drogon/HttpController.h>

#include <string>

#include "../usecases/create_game_usecase.h"
#include "../usecases/presenter.h"

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

class CreateGamePresenter : public Presenter
{
  public:
    void Present(const MachiKoroGame& game) override;
    Json::Value GetViewModel() const;

  private:
    std::string game_id_;
};