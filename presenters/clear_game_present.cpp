#include "clear_game_present.h"

#include "models/events/clear_game_event.h"

ClearGamePresenter::ClearGamePresenter()
    : view_model_(std::make_unique<ViewModel>())
{
}

void ClearGamePresenter::present(Event* event)
{
    auto res = dynamic_cast<ClearGameEvent*>(event);

    status_ = static_cast<drogon::HttpStatusCode>(res->status());

    view_model_.reset();
    view_model_ = std::make_unique<ViewModel>(res->message());
}

ClearGamePresenter::ViewModel::ViewModel(const std::string& msg)
    : message_(msg)
{
}

Json::Value ClearGamePresenter::ViewModel::getJson() const
{
    Json::Value res;
    res["Message"] = message_;
    return res;
}