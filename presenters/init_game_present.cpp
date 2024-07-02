#include "init_game_present.h"

#include "models/architecture_market.h"
#include "models/bank.h"
#include "models/events/event.h"
#include "models/events/init_game_event.h"
#include "utils/util_base.h"

InitGamePresenter::InitGamePresenter(std::shared_ptr<UtilBase> util)
    : util_(util)
    , view_model_(std::make_unique<ViewModel>())
{
}

void InitGamePresenter::present(Event* event)
{
    auto res = dynamic_cast<InitGameEvent*>(event);

    status_ = static_cast<drogon::HttpStatusCode>(res->status());

    view_model_.reset();
    view_model_ = std::make_unique<ViewModel>(util_,
                                              res->message(),
                                              res->bank_balance(),
                                              res->market_cards(),
                                              res->players(),
                                              res->player_name());
}

InitGamePresenter::ViewModel::ViewModel(std::shared_ptr<UtilBase> util,
                                        const std::string& msg,
                                        int bank_balance,
                                        const std::map<std::string, int>& market_cards,
                                        const std::vector<EventPlayer>& players,
                                        const std::string& name)
    : util_(util)
    , message_(msg)
    , bank_balance_(bank_balance)
    , market_cards_(market_cards)
    , players_(players)
    , player_name_(name)
{
}

Json::Value InitGamePresenter::ViewModel::getJson() const
{
    Json::Value res;
    res["Message"] = message_;
    res["BankBalance"] = std::to_string(bank_balance_);

    Json::Value market;
    for (const auto& cards : market_cards_)
    {
        auto& [card_name, card_num] = cards;
        market[card_name] = std::to_string(card_num);
    }
    res["Market"] = market;

    Json::Value players_json(Json::arrayValue);
    for (auto& player : players_)
    {
        Json::Value player_json;
        player_json["Name"] = player.player_name_;
        player_json["Money"] = player.total_coin_;

        Json::Value hand_json;
        for (const auto& landmark : player.landmarks_)
        {
            auto& [card_name, is_activate] = landmark;
            hand_json[card_name] = is_activate;
        }

        std::map<std::string, int> card_count;
        for (const auto& building : player.buildings_)
        {
            auto& [card_name, count] = building;
            card_count[card_name] = count;
        }

        player_json["Hand"] = hand_json;
        players_json.append(player_json);
    }

    res["Players"] = players_json;
    res["NextPlayerName"] = player_name_;

    return res;
}
