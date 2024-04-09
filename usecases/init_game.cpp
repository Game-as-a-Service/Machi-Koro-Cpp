#include "init_game.h"

#include <memory>

#include "models/events/init_game_event.h"

InitGameRequest::InitGameRequest(const std::string& id)
    : id_(id)
{
}

InitGameUsecase::InitGameUsecase(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util)
    : log_(logger)
    , util_(util)
{
}

void InitGameUsecase::execute(InitGameRequest& req, Repository& repo, Presenter& presenter)
{
    // Find.
    auto game = repo.findById(req.id());

    if (!game)
    {
        auto err_event = std::make_shared<InitGameEvent>();
        err_event->set_status(StatusCode::BadRequest);
        err_event->set_message("Failed to init game because cannot find the game ID !");
        log_->error(err_event->message());
        presenter.present(err_event.get());
        return;
    }

    // Modify.
    auto event = game->initGame();

    // Save.
    // Save in memory currently.

    // Push back.
    presenter.present(event.get());
}