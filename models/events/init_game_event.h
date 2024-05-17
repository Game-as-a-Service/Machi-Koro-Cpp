#ifndef MODELS_EVENTS_INIT_GAME_EVENT_H
#define MODELS_EVENTS_INIT_GAME_EVENT_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "models/player.h"
#include "models/events/event.h"
#include "models/events/event_player.h"
#include "utils/util_base.h"

class ArchitectureMarket;
class Bank;

class InitGameEvent : public Event {
public:
    InitGameEvent() = default;

    InitGameEvent(std::shared_ptr<UtilBase> util);

    ~InitGameEvent() = default;

    void set_status(const StatusCode& status) override { status_ = status; }

    StatusCode status() const override { return status_; }

    void set_message(const std::string& str) override { message_ = str; }

    std::string message() const override { return message_; }

    bool set_bank(std::shared_ptr<Bank> bank);

    int bank_balance() const { return bank_balance_; }

    void set_market(ArchitectureMarket* market);

    std::map<std::string, int> market_cards() const { return market_cards_; }

    void set_players(PlayerPtrs* players);

    std::vector<EventPlayer> players() const { return players_; }

    void set_player_name(const std::string& name) { player_name_ = name; }

    std::string player_name() const { return player_name_; }

private:
    std::shared_ptr<UtilBase> util_ = nullptr;

    StatusCode status_ = StatusCode::NoContent;

    std::string message_;

    // Bank's balance.
    int bank_balance_ = 0;

    // Market's cards.
    std::map<std::string, int> market_cards_;

    // Players.
    std::vector<EventPlayer> players_;

    // Player name for the next turn.
    std::string player_name_;
};

#endif  // MODELS_EVENTS_INIT_GAME_EVENT_H