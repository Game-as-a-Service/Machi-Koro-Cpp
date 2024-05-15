#include "models/events/init_game_event.h"

#include "models/bank.h"
#include "models/architecture_market.h"

InitGameEvent::InitGameEvent(std::shared_ptr<UtilBase> util)
    : util_(util)
{
}

void InitGameEvent::set_bank(Bank* bank)
{
    if (!bank) return;
    bank_balance_ = bank->totalCoin();
}

void InitGameEvent::set_market(ArchitectureMarket* market)
{
    if (!market) return;

    auto cards = market->cards();
    for (const auto& c : cards)
    {
        auto& [name, buildings] = c;
        market_cards_[util_->getStringFromCardName(name)] = buildings.size();
    }
}

void InitGameEvent::set_players(PlayerPtrs* players)
{
    if (!players) return;

    for (auto& player : *players)
    {
        EventPlayer ep;
        ep.player_name_ = player->name();
        ep.total_coin_ = player->totalCoin();

        // Landmarks.
        auto landmarks = player->hand().landmarks();
        for (const auto& card : landmarks)
        {
            ep.landmarks_[util_->getStringFromCardName(card->card_name())] = card->is_activate();
        }

        // Buildings.
        auto buildings = player->hand().buildings();
        for (const auto& card : buildings)
        {
            ep.buildings_[util_->getStringFromCardName(card->card_name())]++;
        }

        players_.push_back(std::move(ep));
    }
}