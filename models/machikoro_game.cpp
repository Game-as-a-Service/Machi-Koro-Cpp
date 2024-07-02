#include "models/machikoro_game.h"

#include <format>
#include <vector>
#include <string>

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

    return event;
}

std::unique_ptr<Event> MachiKoroGame::initGame()
{
    // TODO(issue #25): Add a default Dice
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
    if (player_order == -1)
    {
        auto err_event = std::make_shared<RollDiceEvent>();
        err_event->set_status(StatusCode::BadRequest);
        err_event->set_message(std::format("Failed to roll dice because the player_name {} is wrong!", player_name));
        log_->error(err_event->message());
        return err_event;
    }

    auto [ptr1, ptr2] = players_[player_order]->rollDice(*dice_, dice_count);

    operateEffect(ptr1 + ptr2);

    // TODO(Issue #25): Consider more about the effect of landmarks.
    /*
    auto IsLandmarkInHand =
        [](const Hand* hand, const CardName name) -> bool {
            auto it = std::find_if(
                hand->get_landmarks().begin(),
                hand->get_landmarks().end(),
                [&name](Landmark* landmark)  {
                    return landmark->get_name() == name &&
                           landmark->IsActivate();
                }
            );
            return it != hand->get_landmarks().end();
        };

    // Idnetify current player.
    auto player = (*std::find_if(players_.begin(), players_.end(),
        [&player_id](const auto& p) { return p->get_name() == player_id; }
    )).get();

    auto [pt1, pt2] = player->RollDice(dice_count);
    auto event = std::make_unique<RollDiceEvent>(pt1, pt2,
        !(dice_count == 2 && pt2 == 0));
    if (IsLandmarkInHand(player->get_hand(), CardName::RADIO_TOWER))
    {
        // Can reroll the dice or not.
        event->set_can_reroll(true);
        return event;
    }

    // Operate effect.

    // If two points are the same, can roll the dice in next round or not.
    if (pt1 == pt2 &&
        IsLandmarkInHand(player->get_hand(), CardName::AMUSEMENT_PARK))
        event->set_can_roll_next(true);
    return event;
    */
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
    // Get the order of the player
    int player_order = getPlayerIndex(dice_roller->name());
    if (player_order == -1)
    {
        log_->error("Failed to operate effect because the player_name is wrong!");
        return;
    }

    // Get the buildings of the player
    auto buildings = dice_roller->hand().buildings();

    // Get the buildings that can be activated
    std::vector<Building*> activated_buildings;
    for (auto& building : buildings)
    {
        if (building->canActivate(dice_point))
            activated_buildings.push_back(building.get());
    }

    // Sort the buildings according to the IndustryType
    std::sort(activated_buildings.begin(), activated_buildings.end(),
        [](Building* b1, Building* b2) {
            return b1->type() < b2->type();
        });

    // Activate the buildings
    for (auto& building : activated_buildings)
    {
        building->activate(dice_roller, players_, bank_);
    }

    // Check if the player has the landmark
    // and activate the effect of the landmark
    // if the player has the landmark
    // for (auto& landmark : dice_roller->hand().landmarks())
    // {
    //     if (landmark->canActivate(dice_point))
    //         landmark->activate(dice_roller, players_, bank_);
    // }

    // Move to the next player
    current_player_ = (current_player_ + 1) % players_.size();
}