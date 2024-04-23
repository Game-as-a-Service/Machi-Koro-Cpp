#ifndef MODELS_EVENTS_INIT_GAME_EVENT_H
#define MODELS_EVENTS_INIT_GAME_EVENT_H

#include <string>
#include <vector>

#include "event.h"
#include "models/player.h"

class ArchitectureMarket;
class Bank;

class InitGameEvent : public Event {
public:
    InitGameEvent() = default;

    ~InitGameEvent() = default;

    void set_status(const StatusCode& status) override { status_ = status; }

    StatusCode status() const override { return status_; }

    void set_message(const std::string& str) override { message_ = str; }

    std::string message() const override { return message_; }

    void set_bank(Bank* bank) { bank_ = bank; }

    Bank* bank() const { return bank_; }

    void set_market(ArchitectureMarket* market) { market_ = market; }

    ArchitectureMarket* market() const { return market_; }

    void set_players(PlayerPtrs* players) { players_ = players; }

    PlayerPtrs* players() const { return players_; }

    void set_player_name(const std::string& name) { player_name_ = name; }

    std::string player_name() const { return player_name_; }

private:
    StatusCode status_ = StatusCode::NoContent;

    std::string message_;

    Bank* bank_ = nullptr;

    ArchitectureMarket* market_ = nullptr;

    PlayerPtrs* players_ = nullptr;

    // Player name for the next turn.
    std::string player_name_;
};

#endif  // MODELS_EVENTS_INIT_GAME_EVENT_H