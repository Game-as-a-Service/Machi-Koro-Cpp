#include "models/machikoro_game.h"

#include <vector>
#include <string>

#include "models/events/create_game_event.h"
#include "models/events/init_game_event.h"

MachiKoroGame::MachiKoroGame(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util)
    : log_(logger)
    , util_(util)
{
}

std::unique_ptr<Event> MachiKoroGame::createGame(std::vector<PlayerPtr>&& players)
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

std::unique_ptr<Event> MachiKoroGame::initGame()
{
    auto event = std::make_unique<InitGameEvent>(util_);

    if (bank_->totalCoin() != 282)
    {
        event->set_status(StatusCode::BadRequest);
        event->set_message("Failed to init game because bank's total coin is not 282 !");
        log_->error(event->message());
        return event;
    }

    // Allocate money.
    for (auto& player : players_)
    {
        if (!player->gainCoinFromBank(bank_, 3))
        {
            event->set_status(StatusCode::BadRequest);
            event->set_message("Failed to init game because bank_ is nullptr !");
            log_->error(event->message());
            return event;
        }
        else if (player->totalCoin() != 3)
        {
            event->set_status(StatusCode::BadRequest);
            event->set_message("Failed to init game because player's total coin is not 3 !");
            log_->error(event->message());
            return event;
        }
    }

    // Get initial buildings.
    for (auto& player : players_)
    {
        auto wheat_field = market_.drawCard(CardName::WHEAT_FIELD);
        if (!wheat_field)
        {
            event->set_status(StatusCode::BadRequest);
            event->set_message("Failed to init game because cannot draw wheat field card !");
            log_->error(event->message());
            return event;
        }
        player->hand().gainCard(std::move(*wheat_field));

        auto bakery = market_.drawCard(CardName::BAKERY);
        if (!bakery)
        {
            event->set_status(StatusCode::BadRequest);
            event->set_message("Failed to init game because cannot draw bakery card !");
            log_->error(event->message());
            return event;
        }
        player->hand().gainCard(std::move(*bakery));
    }

    log_->info("Bank's total coin: " + std::to_string(bank_->totalCoin()));
    if (bank_->totalCoin() != 282 - 12)
    {
        event->set_status(StatusCode::BadRequest);
        event->set_message("Failed to init game because bank's total coin is not 270 !");
        log_->error(event->message());
        return event;
    }

    // Choose one player to be the player for the first round.
    current_player_ = 0;

    event->set_status(StatusCode::Ok);
    event->set_message("Success to init game.");
    event->set_bank(bank_);
    event->set_market(&market_);
    event->set_players(&players_);
    event->set_player_name(players_[current_player_ % players_.size()]->name());
    log_->info(event->message() + "Game ID: " + game_id_);

    return event;
}