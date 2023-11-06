#include <drogon/drogon.h>
#include <drogon/HttpTypes.h>

#include "../../controllers/utils.h"
#include "../../controllers/in_memory_repository.h"
#include "../../models/card/card.h"
#include "../../models/player.h"

#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>

// TODO: maybe move this to other place, so that other files can use the same address
static const std::string HTTP_ADDRESS = "http://127.0.0.1:8086";

class GameSetupE2ETest: public ::testing::Test {
protected:
  GameSetupE2ETest() {
  }

  ~GameSetupE2ETest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
  InMemoryRepository& repo_ = InMemoryRepository::self();
};

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

// GIVEN_empty_WHEN_createGame_THEN_success
TEST_F(GameSetupE2ETest, CreateGameSuccessfully)
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
    ASSERT_EQ(resp.first, drogon::ReqResult::Ok);
    ASSERT_TRUE(resp.second);
    EXPECT_EQ(resp.second->getStatusCode(), 200);
    EXPECT_FALSE((*resp.second->getJsonObject())[controllers::utils::game_id].asString().empty());

    // Then
    auto game = repo_.FindGameByID((*resp.second->getJsonObject())[controllers::utils::game_id].asString());

    ASSERT_TRUE(game);
    EXPECT_EQ(game->get_game_id(), (*resp.second->getJsonObject())[controllers::utils::game_id].asString());

    auto players = game->get_players();
    EXPECT_EQ(players.size(), 4);

    auto bank = game->get_bank();
    EXPECT_EQ(bank->get_coin(), (282 - 4 * 3));

    for(const auto& player : players) {
        EXPECT_EQ(player->get_coin(), 3);
        auto hand = player->get_hand();

        std::vector<CardName> card_names = {
            CardName::WHEAT_FIELD,
            CardName::BAKERY,
            CardName::SHOPPING_MALL,
            CardName::TRAIN_STATION,
            CardName::AMUSEMENT_PARK,
            CardName::RADIO_TOWER
        };
        EXPECT_EQ(hand->get_buildings().size(), 2);
        for (const auto& card: hand->get_buildings()) {
            EXPECT_NE(std::find(card_names.begin(), card_names.end(), card->get_name()), card_names.end());
        }

        EXPECT_EQ(hand->get_landmarks().size(), 4);
        for (const auto& landmark: hand->get_landmarks()) {
            EXPECT_NE(std::find(card_names.begin(), card_names.end(), landmark->get_name()), card_names.end());
            EXPECT_FALSE(dynamic_cast<Landmark*>(landmark)->IsActivate());
        }
    }

}

//DROGON_TEST(GIVEN_player_has_no_station_WHEN_roll_2_dice_THEN_failed) {
    // Create game
    // send rolldice request (roll 2 dice), then failed

    // Given
    // Json::Value create_json;
    // Json::Value players(Json::arrayValue);
    // players.append("player_a");
    // create_json[controllers::utils::player_names] = players;

    // auto client = drogon::HttpClient::newHttpClient(HTTP_ADDRESS);
    // std::string gameName2 = "Game2";
    // drogon::HttpRequestPtr req1 = getRequestObj("gameName", gameName2, drogon::Post, "/CreateGame/createGame");
    // client->sendRequest(req1, [TEST_CTX](drogon::ReqResult res, const drogon::HttpResponsePtr& resp)
    // {
    //     REQUIRE(res == drogon::ReqResult::Ok);
    //     REQUIRE(resp != nullptr);
    // });

    // When
    // Roll Dice Controller

    //Http request: player name, dice count
//}

//DROGON_TEST(GIVEN_player_has_station_WHEN_rolldice_THEN_success) {
    // Create game

    // give train station to player0
    // send rolldice request (roll 1 dice), then success
    // send rolldice request (roll 2 dice), then success

     //auto player = game->get_players()[0];
    //player->GainBuildingCard(std::make_unique<CardName::TRAIN_STATION>());


// DROGON_TEST(StartGame)
// {
    // GIVEN: Empty

    //auto client= drogon::HttpClient::newHttpClient(HTTP_ADDRESS);
    // WHEN: create game, add three players, and startGame
    // create game
    //string gameName1 = "Game1";
    //sendRequestToServer(client, "gameName", gameName1, drogon::Post, "/CreateGame/createGame");

    // add three players
    //addPlayer("Player1");
    //addPlayer("Player2");
    //addPlayer("Player3");

    // startGame
    /*
    Json::Value requestJson;
    requestJson["gameName"] = "Game1";
    auto req = drogon::HttpRequest::newHttpJsonRequest(requestJson);
    req->setMethod(drogon::Post);
    req->setPath("/StartGame/startGame");

    startGameClient->sendRequest(req, [TEST_CTX](drogon::ReqResult res, const drogon::HttpResponsePtr& resp) {
        REQUIRE(res == drogon::ReqResult::Ok);
        REQUIRE(resp != nullptr);

        CHECK(resp->getStatusCode() == 200);
        CHECK(resp->contentType() == drogon::CT_APPLICATION_JSON);
    });
    */

    // THEN: system creates 108 cards, 282 coins, 2 dices

// }
