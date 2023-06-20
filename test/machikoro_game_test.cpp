#include <drogon/drogon_test.h>
#include <drogon/drogon.h>
#include <drogon/HttpTypes.h>

#include "../controllers/utils.h"
#include "../models/game_repository.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

// TODO: maybe move this to other place, so that other files can use the same address
static const std::string HTTP_ADDRESS = "http://127.0.0.1:8080";

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

DROGON_TEST(GIVEN_empty_WHEN_createGame_THEN_success)
{
    Json::Value create_game_request_json;
    Json::Value player_list(Json::arrayValue);
    player_list.append("player0");
    player_list.append("player1");
    player_list.append("player2");
    player_list.append("player3");
    create_game_request_json[controllers::utils::player_names] = player_list;
    drogon::HttpRequestPtr create_game_req = 
        GetRequestObj(create_game_request_json, drogon::Post, "/CreateGame/createGame");

    auto client = drogon::HttpClient::newHttpClient(HTTP_ADDRESS);
    auto resp = client->sendRequest(create_game_req);
    REQUIRE(resp.first == drogon::ReqResult::Ok);
    REQUIRE(resp.second != nullptr);
    CHECK(resp.second->getStatusCode() == 200);
    CHECK((*resp.second->getJsonObject())[controllers::utils::game_id].asString().empty() == false);
}

/*
// TODO(issue #9): Fix the asynchronous problem so that different test cases won't interfere with each other.
DROGON_TEST(GIVEN_gameExists_WHEN_createGameWithSameName_THEN_reject)
{
    auto client = drogon::HttpClient::newHttpClient(HTTP_ADDRESS);
    std::string gameName2 = "Game2";
    drogon::HttpRequestPtr req1 = getRequestObj("gameName", gameName2, drogon::Post, "/CreateGame/createGame");
    client->sendRequest(req1, [TEST_CTX](drogon::ReqResult res, const drogon::HttpResponsePtr& resp) 
    {
        REQUIRE(res == drogon::ReqResult::Ok);
        REQUIRE(resp != nullptr);
    });

    drogon::HttpRequestPtr req2 = getRequestObj("gameName", gameName2, drogon::Post, "/CreateGame/createGame");
    client->sendRequest(req2, [TEST_CTX](drogon::ReqResult res, const drogon::HttpResponsePtr& resp)
    {
        REQUIRE(res == drogon::ReqResult::Ok);
        REQUIRE(resp != nullptr);
        CHECK(resp->getStatusCode() == 400);
        LOG_INFO << resp->getBody();
    });
    GameRepository::self().ClearAllGames();
}
*/


DROGON_TEST(StartGame)
{
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

}