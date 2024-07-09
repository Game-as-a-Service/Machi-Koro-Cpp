#include "presenters/roll_dice_present.h"

#include "models/architecture_market.h"
#include "models/bank.h"
#include "models/events/event.h"
#include "models/events/roll_dice_event.h"
#include "utils/util_base.h"

RollDicePresenter::RollDicePresenter(std::shared_ptr<UtilBase> util)
    : util_(util)
    , view_model_(std::make_unique<ViewModel>())
{
}

void RollDicePresenter::present(Event* event)
{
    auto res = dynamic_cast<RollDiceEvent*>(event);

    status_ = static_cast<drogon::HttpStatusCode>(res->status());

    view_model_.reset();
    view_model_ = std::make_unique<ViewModel>(util_,
                                              res->message(),
                                              res->bank_balance(),
                                              res->players());
}

RollDicePresenter::ViewModel::ViewModel(std::shared_ptr<UtilBase> util,
                                        const std::string& msg,
                                        int bank_balance,
                                        const std::vector<EventPlayer>& players)
    : util_(util)
    , message_(msg)
    , bank_balance_(bank_balance)
    , players_(players)
{
}

Json::Value RollDicePresenter::ViewModel::getJson() const
{
    Json::Value res;
    res["Message"] = message_;
    res["BankBalance"] = std::to_string(bank_balance_);

    Json::Value players_json(Json::arrayValue);
    for (auto& player : players_)
    {
        Json::Value player_json;
        player_json["Name"] = player.player_name_;
        player_json["Money"] = player.total_coin_;

        players_json.append(player_json);
    }
    res["Players"] = players_json;

    return res;
}
