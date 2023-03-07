#include <drogon/drogon_test.h>
#include <drogon/drogon.h>
#include <drogon/HttpTypes.h>

#include <iostream>
#include <string>

// TODO: maybe move this to other place, so that other files can use the same address
static const std::string HTTP_ADDRESS = "http://127.0.0.1:8080";

// drogon::ReqResult sendHttpRequest(const HttpMethod method, Jason::Value jsonValue)

DROGON_TEST(StartGame)
{
    // GIVEN: Empty

    // WHEN: startGame
    auto startGameClient = drogon::HttpClient::newHttpClient("http://127.0.0.1:8080");

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

    // THEN: system creates 108 cards, 282 coins, 2 dices

}