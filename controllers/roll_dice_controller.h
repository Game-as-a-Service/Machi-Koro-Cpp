#pragma once

#include <drogon/HttpController.h>
#include <string>

#include "../usecases/roll_dice_usecase.h"
#include "../usecases/presenter.h"

using namespace drogon;

class RollDice : public drogon::HttpController<RollDice>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(RollDice::rollDice, "/rollDice", Post);
    METHOD_LIST_END

    void rollDice(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback);
};

class RollDicePresenter : public Presenter
{
  public:
    void Present(const MachiKoroGame& game) override;
    Json::Value GetViewModel() const;

  private:
    std::string game_id_;
};