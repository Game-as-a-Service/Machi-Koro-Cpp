#include "init_game_controller.h"

#include "repos/memory_repository.h"
#include "usecases/init_game.h"
#include "presenters/init_game_present.h"

void InitGame::initGame(const HttpRequestPtr& req,
                        std::function<void(const HttpResponsePtr&)>&& callback,
                        const std::string& game_id)
{
    log_->info("Receive init game request. ID: " + game_id);

    InitGameRequest init_req(game_id);
    InitGameUsecase uc(log_, util_);
    InitGamePresenter presenter(util_);

    uc.execute(init_req, MemoryRepository::self(), presenter);

    auto res = HttpResponse::newHttpJsonResponse(presenter.view_model()->getJson());
    res->setStatusCode(presenter.status());
    callback(res);
}