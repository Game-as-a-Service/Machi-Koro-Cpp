#include "models/events/init_game_event.h"

#include "models/bank.h"
#include "models/architecture_market.h"

InitGameEvent::InitGameEvent(std::shared_ptr<UtilBase> util)
    : util_(util)
{
}

bool InitGameEvent::set_bank(std::shared_ptr<Bank> bank)
{
    if (!bank) return false;
    bank_balance_ = bank->totalCoin();
    return true;
}

void InitGameEvent::set_market(ArchitectureMarket* market)
{
    if (!market) return;

    auto cards = market->cards();
    for (const auto& card : cards)
    {
        market_cards_[util_->getStringFromCardName(card.first)] = card.second;
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