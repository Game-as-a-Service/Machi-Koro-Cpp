#include "models/machikoro_game.h"

#include <format>
#include <vector>
#include <string>

#include "models/dice.h"
#include "models/events/create_game_event.h"
#include "models/events/init_game_event.h"
#include "models/events/roll_dice_event.h"

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

    dice_ = std::make_unique<Dice>();

    return event;
}

std::unique_ptr<Event> MachiKoroGame::initGame()
{
    auto event = std::make_unique<InitGameEvent>(util_);

    // Allocate money.
    for (auto& player : players_) player->gainCoinFromBank(bank_, 3);

    // Get initial buildings.
    for (auto& player : players_)
    {
        player->hand().gainCard(market_.drawCard(CardName::WHEAT_FIELD));
        player->hand().gainCard(market_.drawCard(CardName::BAKERY));
    }

    // Choose one player to be the player for the first round.
    current_player_ = 0;

    event->set_status(StatusCode::Ok);
    event->set_message("Success to init game.");
    event->set_bank(&bank_);
    event->set_market(&market_);
    event->set_players(&players_);
    event->set_player_name(players_[current_player_ % players_.size()]->name());
    log_->info(event->message() + "Game ID: " + game_id_);

    return event;
}

std::unique_ptr<Event> MachiKoroGame::rollDice(const std::string& player_name, int dice_count)
{
    //Get the order of the player
    int player_order = getPlayerIndex(player_name);

    if (player_order == -1 || player_order != current_player_)
    {
        auto err_event = std::make_unique<RollDiceEvent>();
        err_event->set_status(StatusCode::BadRequest);
        std::string error_msg = player_order == -1 ?
                                std::format("Failed to roll dice because the player_name {} is wrong!", player_name) :
                                std::format("Failed to roll dice because the player_name {} is not the current player!", player_name);
        err_event->set_message(error_msg);
        log_->error(err_event->message());
        return err_event;
    }

    auto [ptr1, ptr2] = players_[player_order]->rollDice(*dice_, dice_count);
    operateEffect(ptr1 + ptr2);

    auto event = std::make_unique<RollDiceEvent>(util_);
    event->set_status(StatusCode::Ok);
    event->set_message("Success to roll dice.");
    event->set_bank(&bank_);
    event->set_players(&players_);
    log_->info(event->message() + "Game ID: " + game_id_);

    return event;
}

int MachiKoroGame::getPlayerIndex(const std::string& player_name)
{
    for (int i = 0; i < players_.size(); i++)
    {
        if (players_[i]->name() == player_name)
            return i;
    }
    return -1;
}

void MachiKoroGame::operateEffect(int dice_point)
{
    // Follow the order according to the IndustryType of each card in hand
    // e.g. IndustryType::RESTAURANT (player2(p2) -> p3 -> p4 -> p1) ->
    //      IndustryType::SECONDARY_INDUSTRY (p2 -> p3 -> p4 -> p1) ->
    //      IndustryType::PRIMARY_INDUSTRY (p2 -> p3 -> p4 -> p1) ->
    //      IndustryType::IMPORTANT_BUILDING (p2 -> p3 -> p4 -> p1)
    std::vector<Player*> players;
    for (auto& player : players_)
        players.push_back(player.get());

    Player* dice_roller = players[current_player_];

    for (int i = 0; i < players_.size(); i++)
    {
        auto player = players[(current_player_ + i) % players_.size()];
        player->operateEffect(dice_roller, players, dice_point, IndustryType::RESTAURANT, &bank_);
    }
    for (int i = 0; i < players_.size(); i++)
    {
        auto player = players[(current_player_ + i) % players_.size()];
        player->operateEffect(dice_roller, players, dice_point, IndustryType::SECONDARY_INDUSTRY, &bank_);
    }
    for (int i = 0; i < players_.size(); i++)
    {
        auto player = players[(current_player_ + i) % players_.size()];
        player->operateEffect(dice_roller, players, dice_point, IndustryType::PRIMARY_INDUSTRY, &bank_);
    }
    for (int i = 0; i < players_.size(); i++)
    {
        auto player = players[(current_player_ + i) % players_.size()];
        player->operateEffect(dice_roller, players, dice_point, IndustryType::IMPORTANT_BUILDING, &bank_);
    }

}