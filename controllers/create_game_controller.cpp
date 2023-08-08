#include "create_game_controller.h"

#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

// Add definition of your processing function here
// TODO: deal with same gameName
void CreateGame::createGame(const HttpRequestPtr &req,
               std::function<void (const HttpResponsePtr &)> &&callback) {
    LOG_INFO << "Receive createGame request.";

    auto json = req->getJsonObject();
    if (!json)
    {
        auto resp = HttpResponse::newHttpResponse();
        resp->setBody("missing 'value' in body");
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }
    
    std::vector<std::string> player_names = 
        controllers::utils::JsonValueToVectorOfString((*json)["playerNames"]);
    
    CreateGamePresenter presenter;
    
    CreateGameUsecase uc;
    uc.CreateGameExecute(
        CreateGameUsecaseRequest(player_names), presenter);
    
    auto resp = HttpResponse::newHttpJsonResponse(presenter.GetViewModel());
    callback(resp);
}

void CreateGamePresenter::Present(const MachiKoroGame& game)
{
    game_id_ = game.get_game_id();
}

Json::Value CreateGamePresenter::GetViewModel() const
{
    Json::Value res;
    res["result"] = "ok";
    res[controllers::utils::game_id] = game_id_; 
    return res;
}
