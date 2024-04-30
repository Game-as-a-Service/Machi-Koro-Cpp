#ifndef PRESENTERS_CLEAR_GAME_PRESENT_H
#define PRESENTERS_CLEAR_GAME_PRESENT_H

#include <string>
#include <memory>

#include "json/value.h"
#include "drogon/HttpTypes.h"
#include "presenter.h"

class Event;

class ClearGamePresenter : public Presenter {
    /**
     * @brief Construct the result datas those will pass back to front-end.
     */
    class ViewModel {
    public:
        ViewModel() = default;

        ViewModel(const std::string& msg);

        ~ViewModel() = default;

        Json::Value getJson() const;

    private:
        // The self-defined message.
        std::string message_;
    };

public:
    ClearGamePresenter();

    ~ClearGamePresenter() = default;

    // Inherited from the class 'Presenter'.
    void present(Event* event) override;

    // Get current response status.
    drogon::HttpStatusCode status() const { return status_; }

    // Get current response content (view model).
    const ViewModel* view_model() const { return view_model_.get(); }

private:
    // Status code.
    drogon::HttpStatusCode status_ = drogon::HttpStatusCode::k204NoContent;

    // View Model.
    std::unique_ptr<ViewModel> view_model_ = nullptr;
};

#endif  // PRESENTERS_CLEAR_GAME_PRESENT_H