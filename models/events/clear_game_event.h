#ifndef MODELS_EVENTS_CLEAR_GAME_EVENT_H
#define MODELS_EVENTS_CLEAR_GAME_EVENT_H

#include <string>

#include "event.h"

class ClearGameEvent : public Event {
public:
    ClearGameEvent() = default;

    ~ClearGameEvent() = default;

    void set_status(const StatusCode& status) override { status_ = status; }

    StatusCode status() const override { return status_; }

    void set_message(const std::string& str) override { message_ = str; }

    std::string message() const override { return message_; }

private:
    // Status code.
    StatusCode status_ = StatusCode::NoContent;

    // Message.
    std::string message_;
};

#endif  // MODELS_EVENTS_CLEAR_GAME_EVENT_H