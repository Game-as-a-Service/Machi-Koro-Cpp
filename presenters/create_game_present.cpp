#include "create_game_present.h"

#include "models/events/create_game_event.h"
#include "models/events/event.h"

CreateGamePresenter::CreateGamePresenter()
    : view_model_(std::make_unique<ViewModel>())
{
}

void CreateGamePresenter::present(Event* event)
{
    auto res = dynamic_cast<CreateGameEvent*>(event);

    status_ = static_cast<drogon::HttpStatusCode>(res->status());

    view_model_.reset();
    view_model_ = std::make_unique<ViewModel>(res->message(), res->game_id());
}

CreateGamePresenter::ViewModel::ViewModel(const std::string& msg, const std::string& id)
    : message_(msg)
    , game_id_(id)
{
}

Json::Value CreateGamePresenter::ViewModel::getJson() const
{
    Json::Value res;
    res["Message"] = message_;
    res["GameID"] = game_id_;
    return res;
}