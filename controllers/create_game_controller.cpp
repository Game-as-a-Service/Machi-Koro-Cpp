#include "create_game_controller.h"

#include <vector>
#include <string>

#include "utils/util_impl.h"
#include "loggers/logger_impl.h"
#include "repos/memory_repository.h"
#include "usecases/create_game.h"
#include "presenters/create_game_present.h"

void CreateGame::createGame(const HttpRequestPtr& req,
                            std::function<void(const HttpResponsePtr&)>&& callback)
{
    log_->info("Receive create game request.");

    auto req_json = req->getJsonObject();
    std::vector<std::string> names;
    for (const auto& name : (*req_json)["playerNames"]) names.push_back(name.asString());

    CreateGameRequest create_req(names);
    CreateGameUsecase uc(log_, util_);
    CreateGamePresenter presenter;

    uc.execute(create_req, MemoryRepository::self(), presenter);

    auto res = HttpResponse::newHttpJsonResponse(presenter.view_model()->getJson());
    res->setStatusCode(presenter.status());
    callback(res);
}