#ifndef MODELS_EVENTS_CREATE_GAME_EVENT_H
#define MODELS_EVENTS_CREATE_GAME_EVENT_H

#include <string>

#include "event.h"

class CreateGameEvent : public Event {
public:
    CreateGameEvent() = default;

    ~CreateGameEvent() = default;

    void set_status(const StatusCode& status) override { status_ = status; }

    StatusCode status() const override { return status_; }

    void set_message(const std::string& str) override { message_ = str; }

    std::string message() const override { return message_; }

    void set_game_id(const std::string& id) { game_id_ = id; }

    std::string game_id() const { return game_id_; }

private:
    // Status code.
    StatusCode status_ = StatusCode::NoContent;

    // Message.
    std::string message_;

    // Game ID (pass back).
    std::string game_id_;
};

#endif  // MODELS_EVENTS_CREATE_GAME_EVENT_H