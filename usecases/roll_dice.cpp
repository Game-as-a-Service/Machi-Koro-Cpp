#include "roll_dice.h"

#include <memory>

#include "loggers/logger_base.h"
#include "models/events/roll_dice_event.h"
#include "models/machikoro_game.h"
#include "presenters/presenter.h"
#include "repos/repository.h"
#include "utils/util_base.h"

RollDiceRequest::RollDiceRequest(const std::string& id, const std::string& player_name, int dice_count)
    : id_(id), player_name_(player_name), dice_count_(dice_count)
{
}

RollDiceUsecase::RollDiceUsecase(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util)
    : log_(logger)
    , util_(util)
{
}

void RollDiceUsecase::execute(RollDiceRequest& req, Repository& repo, Presenter& presenter)
{
    // Find.
    auto game = repo.findById(req.id());

    // TODO: Can we reuse this code for every usecase?
    if (!game)
    {
        auto err_event = std::make_shared<RollDiceEvent>();
        err_event->set_status(StatusCode::BadRequest);
        err_event->set_message("Failed to roll dice because cannot find the game ID !");
        log_->error(err_event->message());
        presenter.present(err_event.get());
        return;
    }

    // Modify.
    auto event = game->rollDice(req.player_name(), req.dice_count());

    // Save.
    // Save in memory currently.

    // Push back.
    presenter.present(event.get());
}