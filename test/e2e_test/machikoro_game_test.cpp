#include <drogon/drogon_test.h>
#include <drogon/drogon.h>
#include <drogon/HttpTypes.h>

#include "../../controllers/utils.h"
#include "../../controllers/in_memory_repository.h"
#include "../../models/card/card.h"
#include "../../models/player.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

// TODO: maybe move this to other place, so that other files can use the same address
static const std::string HTTP_ADDRESS = "http://127.0.0.1:8086";

drogon::HttpRequestPtr GetRequestObj(const Json::Value& request_json,
                                     drogon::HttpMethod method, const std::string path)
{
    auto req = drogon::HttpRequest::newHttpJsonRequest(request_json);
    req->setMethod(method);
    req->setPath(path);
    return req;
}

drogon::HttpRequestPtr GetRequestObj(const std::string json_key_name,
                const std::string json_value_name, drogon::HttpMethod method, const std::string path)
{
    Json::Value request_json;
    request_json[json_key_name] = json_value_name;
    return GetRequestObj(request_json, method, path);
}

DROGON_TEST(GIVEN_4_players_WHEN_game_setup_THEN_xxxxxx)
{
    // Given
    Json::Value create_game_request_json;
    Json::Value player_list(Json::arrayValue);
    player_list.append("player0");
    player_list.append("player1");
    player_list.append("player2");
    player_list.append("player3");
    create_game_request_json[controllers::utils::player_names] = player_list;

    // When
    drogon::HttpRequestPtr create_game_req =
        GetRequestObj(create_game_request_json, drogon::Post, "/CreateGame/createGame");
    auto client = drogon::HttpClient::newHttpClient(HTTP_ADDRESS);
    auto resp = client->sendRequest(create_game_req);
    REQUIRE(resp.first == drogon::ReqResult::Ok);
    REQUIRE(resp.second != nullptr);
    CHECK(resp.second->getStatusCode() == 200);
    CHECK((*resp.second->getJsonObject())[controllers::utils::game_id].asString().empty() == false);

    // Then
    auto game = InMemoryRepository::self().FindGameByID((*resp.second->getJsonObject())[controllers::utils::game_id].asString());

    REQUIRE(game != nullptr);
    CHECK(game->get_game_id() == (*resp.second->getJsonObject())[controllers::utils::game_id].asString());

    auto players = game->get_players();
    CHECK(players.size() == 4);

    auto bank = game->get_bank();
    CHECK(bank->get_coin() == (282 - 4 * 3));

    // TODO: check card types, and check landmark
    for(const auto& player : players) {
        CHECK(player->get_coin() == 3);
        auto hand = player->get_hand();

        std::vector<CardName> card_names = {
            CardName::WHEAT_FIELD,
            CardName::BAKERY,
            CardName::SHOPPING_MALL,
            CardName::TRAIN_STATION,
            CardName::AMUSEMENT_PARK,
            CardName::RADIO_TOWER
        };
        CHECK(hand->get_buildings().size() == 2);
        for (const auto& card: hand->get_buildings()) {
            CHECK(std::find(card_names.begin(), card_names.end(), card->get_name()) != card_names.end());
        }

        CHECK(hand->get_landmarks().size() == 4);
        for (const auto& landmark: hand->get_landmarks()) {
            CHECK(std::find(card_names.begin(), card_names.end(), landmark->get_name()) != card_names.end());
            CHECK(dynamic_cast<Landmark*>(landmark)->IsActivate() == false);
        }
    }

}

DROGON_TEST(GIVEN_player_has_no_station_WHEN_roll_2_dice_THEN_failed) {
    // Create game
    // send rolldice request (roll 2 dice), then failed

    // Given
    Json::Value create_json;
    Json::Value players(Json::arrayValue);
    players.append("player_a");
    create_json[controllers::utils::player_names] = players;

    auto client = drogon::HttpClient::newHttpClient(HTTP_ADDRESS);
    drogon::HttpRequestPtr create_req =
        GetRequestObj(create_json, drogon::Post, "/CreateGame/createGame");
    auto create_resp = client->sendRequest(create_req);
    auto game = InMemoryRepository::self()
        .FindGameByID(
            (*create_resp.second->getJsonObject())[controllers::utils::game_id].asString()
        );

    // When
    // Roll Dice Controller

    //Http request: player name, dice count
}

DROGON_TEST(GIVEN_player_has_station_WHEN_rolldice_THEN_success) {
    // Create game

    // give train station to player0
    // send rolldice request (roll 1 dice), then success
    // send rolldice request (roll 2 dice), then success

     //auto player = game->get_players()[0];
    //player->GainBuildingCard(std::make_unique<CardName::TRAIN_STATION>());


}
