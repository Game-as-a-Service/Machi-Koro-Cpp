#include "roll_dice_controller.h"

#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "in_memory_repository.h"

void RollDice::rollDice(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback) {
    LOG_INFO << "Receive rollDice request.";

    auto json = req->getJsonObject();
    if (!json)
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody("missing 'value' in body");
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }

    // std::vector<std::string> player_names =
    //     controllers::utils::JsonValueToVectorOfString((*json)["playerNames"]);

    RollDicePresenter presenter;

    // RollDiceUsecase uc;
    // uc.RollDiceExecute(
    //     RollDiceUsecaseRequest(player_names), InMemoryRepository::self(), presenter);

    auto resp = HttpResponse::newHttpJsonResponse(presenter.GetViewModel());
    callback(resp);
}

void RollDicePresenter::Present(const MachiKoroGame& game)
{
    //game_id_ = game.get_game_id();
}

Json::Value RollDicePresenter::GetViewModel() const
{
    Json::Value res;
    //res["result"] = "ok";
    //res[controllers::utils::game_id] = game_id_;
    return res;
}
