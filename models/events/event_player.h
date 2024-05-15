#ifndef MODELS_EVENTS_EVENT_PLAYER_H
#define MODELS_EVENTS_EVENT_PLAYER_H

#include <string>
#include <map>

/**
 * @note: Used to pass the player's informations back to Presenter.
 */
class EventPlayer {
public:
    std::string player_name_;

    int total_coin_ = 0;

    std::map<std::string, bool> landmarks_;

    std::map<std::string, int> buildings_;
};

#endif  // MODELS_EVENTS_EVENT_PLAYER_H