#include "models/events/roll_dice_event.h"

#include "models/bank.h"
#include "models/architecture_market.h"

RollDiceEvent::RollDiceEvent(std::shared_ptr<UtilBase> util)
    : util_(util)
{
}

void RollDiceEvent::set_bank(Bank* bank) {
    if (!bank) return;
    bank_balance_ = bank->totalCoin();
}

void RollDiceEvent::set_players(PlayerPtrs* players)
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