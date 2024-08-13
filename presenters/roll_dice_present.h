#ifndef PRESENTERS_ROLL_DICE_PRESENT_H
#define PRESENTERS_ROLL_DICE_PRESENT_H

#include <utility>
#include <string>
#include <memory>

#include "json/value.h"
#include "drogon/HttpTypes.h"
#include "presenter.h"
#include "models/events/event_player.h"

class Event;
class UtilBase;

class RollDicePresenter : public Presenter {
    /**
     * @brief Construct the result datas those will pass back to front-end.
     */
    class ViewModel {
    public:
        ViewModel() = default;

        ViewModel(std::shared_ptr<UtilBase> util,
                  const std::string& msg,
                  int bank_balance,
                  const std::vector<EventPlayer>& players,
                  std::pair<int, int> dice_points);

        ~ViewModel() = default;

        Json::Value getJson() const;

    private:
        std::shared_ptr<UtilBase> util_ = nullptr;

        // The self-defined message.
        std::string message_;

        // Bank balance.
        int bank_balance_;

        // Players.
        std::vector<EventPlayer> players_;

        std::pair<int, int> dice_points_;
    };

public:
    RollDicePresenter(std::shared_ptr<UtilBase> util);

    ~RollDicePresenter() = default;

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

#endif  // PRESENTERS_ROLL_DICE_PRESENT_H
