#ifndef PRESENTERS_CREATE_GAME_PRESENT_H
#define PRESENTERS_CREATE_GAME_PRESENT_H

#include <string>
#include <memory>

#include "json/value.h"
#include "drogon/HttpTypes.h"
#include "presenters/presenter.h"
#include "models/events/event.h"

class CreateGamePresenter : public Presenter {
    // Construct the result datas those will pass back to front-end.
    class ViewModel {
    public:
        ViewModel() = default;

        ViewModel(const std::string& msg, const std::string& id);

        ~ViewModel() = default;

        Json::Value getJson() const;

    private:
        // The self-defined message.
        std::string message_;

        // Game ID.
        std::string game_id_;
    };

public:
    CreateGamePresenter();

    ~CreateGamePresenter() = default;

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

#endif  // PRESENTERS_CREATE_GAME_PRESENT_H