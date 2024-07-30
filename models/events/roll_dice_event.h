#ifndef MODELS_EVENTS_ROLL_DICE_EVENT_H
#define MODELS_EVENTS_ROLL_DICE_EVENT_H

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "models/player.h"
#include "models/events/event.h"
#include "models/events/event_player.h"
#include "utils/util_base.h"

class Bank;

class RollDiceEvent : public Event {
public:
    RollDiceEvent() = default;

    RollDiceEvent(std::shared_ptr<UtilBase> util);

    ~RollDiceEvent() = default;

    void set_status(const StatusCode& status) override { status_ = status; }

    StatusCode status() const override { return status_; }

    void set_message(const std::string& str) override { message_ = str; }

    std::string message() const override { return message_; }

    void set_bank(Bank* bank);

    int bank_balance() const { return bank_balance_; }

    void set_players(PlayerPtrs* players);

    std::vector<EventPlayer> players() const { return players_; }

private:
    std::shared_ptr<UtilBase> util_ = nullptr;

    StatusCode status_ = StatusCode::NoContent;

    std::string message_;

    // // Bank's balance.
    int bank_balance_ = 0;

    // // Players.
    std::vector<EventPlayer> players_;
};

#endif  // MODELS_EVENTS_ROLL_DICE_EVENT_H