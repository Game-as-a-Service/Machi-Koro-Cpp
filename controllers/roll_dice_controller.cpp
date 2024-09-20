#include "roll_dice_controller.h"

#include <vector>
#include <string>

#include "loggers/logger_base.h"
#include "presenters/roll_dice_present.h"
#include "repos/memory_repository.h"
#include "usecases/roll_dice.h"
#include "utils/util_base.h"

void RollDice::rollDice(const HttpRequestPtr& req,
                        std::function<void(const HttpResponsePtr&)>&& callback,
                        const std::string& game_id)
{
    log_->info("Receive create game request.");

    auto req_json = req->getJsonObject();
    std::string player_name = (*req_json)["playerName"].asString();
    int dice_count = (*req_json)["diceCount"].asInt();

    RollDiceRequest roll_req(game_id, player_name, dice_count);
    RollDiceUsecase uc(log_, util_);
    RollDicePresenter presenter(util_);

    uc.execute(roll_req, MemoryRepository::self(), presenter);

    auto res = HttpResponse::newHttpJsonResponse(presenter.view_model()->getJson());
    res->setStatusCode(presenter.status());
    callback(res);
}