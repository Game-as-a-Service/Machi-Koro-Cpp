#include "clear_game_controller.h"

#include "repos/memory_repository.h"
#include "usecases/clear_game.h"
#include "presenters/clear_game_present.h"

void ClearGame::clearGame(const HttpRequestPtr& req,
                          std::function<void(const HttpResponsePtr&)>&& callback,
                          const std::string& game_id)
{
    log_->info("Receive clear game request. ID: " + game_id);

    ClearGameRequest clear_req(game_id);
    ClearGameUsecase uc(log_, util_);
    ClearGamePresenter presenter;

    uc.execute(clear_req, MemoryRepository::self(), presenter);

    auto res = HttpResponse::newHttpJsonResponse(presenter.view_model()->getJson());
    res->setStatusCode(presenter.status());
    callback(res);
}