#include "models/machikoro_game.h"

#include <vector>
#include <string>

#include "events/create_game_event.h"

MachiKoroGame::MachiKoroGame(std::shared_ptr<Logger> logger, std::shared_ptr<Util> util)
    : log_(logger)
    , util_(util)
{
}

std::unique_ptr<Event> MachiKoroGame::createGame(std::vector<Player>&& players)
{
    auto event = std::make_unique<CreateGameEvent>();

    if (players.empty() || players.size() > 4)
    {
        event->set_status(StatusCode::BadRequest);
        event->set_message("The number of players cannot empty or exceed 4 !");
        log_->error("Failed to create game ! " + event->message());
        return event;
    }

    game_id_ = util_->generateUUID();
    players_ = std::move(players);

    event->set_status(StatusCode::Ok);
    event->set_message("Success to create game.");
    event->set_game_id(game_id_);
    log_->info(event->message() + " Game ID: " + game_id_);

    return event;
}