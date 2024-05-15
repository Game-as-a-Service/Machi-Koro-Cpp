#ifndef PRESENTERS_INIT_GAME_PRESENT_H
#define PRESENTERS_INIT_GAME_PRESENT_H

#include <string>
#include <memory>

#include "json/value.h"
#include "drogon/HttpTypes.h"
#include "presenter.h"
#include "models/events/event_player.h"

class Event;
class UtilBase;

class InitGamePresenter : public Presenter {
    /**
     * @brief Construct the result datas those will pass back to front-end.
     */
    class ViewModel {
    public:
        ViewModel() = default;

        ViewModel(std::shared_ptr<UtilBase> util,
                  const std::string& msg,
                  int bank_balance,
                  const std::map<std::string, int>& market_cards,
                  const std::vector<EventPlayer>& players,
                  const std::string& name);

        ~ViewModel() = default;

        Json::Value getJson() const;

    private:
        std::shared_ptr<UtilBase> util_ = nullptr;

        // The self-defined message.
        std::string message_;

        // Bank balance.
        int bank_balance_;

        // Market cards.
        std::map<std::string, int> market_cards_;

        // Players.
        std::vector<EventPlayer> players_;

        // Player for the next turn.
        std::string player_name_;
    };

public:
    InitGamePresenter(std::shared_ptr<UtilBase> util);

    ~InitGamePresenter() = default;

    // Inherited from the class 'Presenter'.
    void present(Event* event) override;

    // Get current response status.
    drogon::HttpStatusCode status() const { return status_; }

    // Get current response content (view model).
    const ViewModel* view_model() const { return view_model_.get(); }

private:
    std::shared_ptr<UtilBase> util_ = nullptr;

    drogon::HttpStatusCode status_ = drogon::HttpStatusCode::k204NoContent;

    std::unique_ptr<ViewModel> view_model_ = nullptr;
};

#endif  // PRESENTERS_INIT_GAME_PRESENT_H