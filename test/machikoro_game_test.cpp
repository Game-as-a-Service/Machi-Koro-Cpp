#include <drogon/drogon_test.h>
#include <drogon/drogon.h>
#include <drogon/HttpTypes.h>

#include "../models/game_repository.h"

#include <iostream>
#include <string>

// TODO: maybe move this to other place, so that other files can use the same address
static const std::string HTTP_ADDRESS = "http://127.0.0.1:8080";

drogon::HttpRequestPtr getRequestObj(const std::string jsonKeyName, 
                const std::string jsonValueName, drogon::HttpMethod method, const std::string path)
{ 
    Json::Value requestJson;
    requestJson[jsonKeyName] = jsonValueName; 
    auto req = drogon::HttpRequest::newHttpJsonRequest(requestJson);
    req->setMethod(method);
    req->setPath(path);
    LOG_INFO << "sendRequest: json" << jsonKeyName << "] = " << jsonValueName << ". Path = " << path;
    return req;
}

DROGON_TEST(GIVEN_empty_WHEN_createGame_THEN_success)
{
    auto client = drogon::HttpClient::newHttpClient(HTTP_ADDRESS);
    std::string gameName1 = "Game1";
    drogon::HttpRequestPtr req1 = getRequestObj("gameName", gameName1, drogon::Post, "/CreateGame/createGame");
    client->sendRequest(req1, [TEST_CTX](drogon::ReqResult res, const drogon::HttpResponsePtr& resp) 
    {
        REQUIRE(res == drogon::ReqResult::Ok);
        REQUIRE(resp != nullptr);
        CHECK(resp->getStatusCode() == 200);
        LOG_INFO << resp->getBody();
    });
    GameRepository::self().ClearAllGames();
}

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