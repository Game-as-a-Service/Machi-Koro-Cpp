#include "clear_game.h"

#include <memory>

#include "loggers/logger_base.h"
#include "models/events/clear_game_event.h"
#include "presenters/presenter.h"
#include "repos/repository.h"
#include "utils/util_base.h"

ClearGameRequest::ClearGameRequest(const std::string& id)
    : id_(id)
{
}

ClearGameUsecase::ClearGameUsecase(std::shared_ptr<LoggerBase> logger,
                                   std::shared_ptr<UtilBase> util)
    : log_(logger)
    , util_(util)
{
}

void ClearGameUsecase::execute(ClearGameRequest& req, Repository& repo, Presenter& presenter)
{
    auto is_success = repo.clear_game(req.id());
    auto event = std::make_unique<ClearGameEvent>();

    if (is_success)
    {
        event->set_status(StatusCode::Ok);
        event->set_message("Success to clear game.");
        log_->info(event->message());
    }
    else
    {
        event->set_status(StatusCode::BadRequest);
        event->set_message("Failed to clear game because cannot find the game ID !");
        log_->error(event->message());
    }

    presenter.present(event.get());
}