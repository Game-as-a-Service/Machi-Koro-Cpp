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
    view_model_ = std::make_unique<ViewModel>(
        util_, res->message(), res->bank(), res->market(), res->players(), res->player_name());
}

InitGamePresenter::ViewModel::ViewModel(std::shared_ptr<UtilBase> util,
                                        const std::string& msg,
                                        Bank* bank,
                                        ArchitectureMarket* market,
                                        PlayerPtrs* players,
                                        const std::string& name)
    : util_(util)
    , message_(msg)
    , bank_(bank)
    , market_(market)
    , players_(players)
    , player_name_(name)
{
}

InitGamePresenter::ViewModel::~ViewModel()
{
    bank_ = nullptr;
    market_ = nullptr;
    players_ = nullptr;
}

Json::Value InitGamePresenter::ViewModel::getJson() const
{
    Json::Value res;
    res["Message"] = message_;
    res["BankBalance"] = std::to_string(bank_->totalCoin());

    Json::Value market;
    const auto& market_cards = market_->cards();
    for (const auto& cards : market_cards)
    {
        auto& [name, card] = cards;
        market[util_->getStringFromCardName(name)] = std::to_string(card.size());
    }
    res["Market"] = market;

    Json::Value players_json(Json::arrayValue);
    for (auto& player : *players_)
    {
        Json::Value player_json;
        player_json["Name"] = player->name();
        player_json["Money"] = player->totalCoin();

        Json::Value hand_json;
        for (auto& landmark : player->hand().landmarks())
            hand_json[util_->getStringFromCardName(landmark->card_name())] =
                landmark->is_activate();

        std::map<std::string, int> card_count;
        for (auto& building : player->hand().buildings())
            card_count[util_->getStringFromCardName(building->card_name())]++;
        for (auto& building : card_count)
            hand_json[building.first] = building.second;

        player_json["Hand"] = hand_json;
        players_json.append(player_json);
    }

    res["Players"] = players_json;
    res["NextPlayerName"] = player_name_;

    return res;
}
