#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <drogon/drogon.h>
#include <drogon/HttpTypes.h>

#include <string>

#include "test_def.h"
#include "repos/repository.h"
#include "repos/memory_repository.h"

using ::testing::Eq;
using ::testing::NotNull;
using ::testing::StrNe;

class TestCreateGame : public ::testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
        // Clear Game.
        if (!game_id_.empty())
        {
            Json::Value req_body;
            auto req = drogon::HttpRequest::newHttpJsonRequest(req_body);
            req->setMethod(drogon::HttpMethod::Delete);
            req->setPath("/ClearGame/" + game_id_);
            client_->sendRequest(req);
        }
    }

    // Repo.
    Repository& repo_ = MemoryRepository::self();

    // Client.
    drogon::HttpClientPtr client_ = drogon::HttpClient::newHttpClient(HTTP_ADDR);

    // Current Game ID in each test cases.
    std::string game_id_;
};

TEST_F(TestCreateGame, Given_WhenNoPlayersJoinTheGame_ThenFailedToCreateGame)
{
    Json::Value req_body;
    auto req = drogon::HttpRequest::newHttpJsonRequest(req_body);
    req->setMethod(drogon::HttpMethod::Post);
    req->setPath("/CreateGame/");

    auto res = client_->sendRequest(req);
    ASSERT_THAT(res.first, Eq(drogon::ReqResult::Ok));
    ASSERT_THAT(res.second, NotNull());

    auto res_status = (*res.second).getStatusCode();
    ASSERT_THAT(res_status, Eq(drogon::HttpStatusCode::k400BadRequest));

    auto& res_body = *((*res.second).getJsonObject());
    ASSERT_THAT(res_body["Message"].asString(), StrNe(""));
}

TEST_F(TestCreateGame, Given_When5PlayersJoinTheGame_ThenFailedToCreateGame)
{
    Json::Value req_body;
    Json::Value player_names(Json::arrayValue);
    player_names.append("Himmel");
    player_names.append("Frieren");
    player_names.append("Heiter");
    player_names.append("Eisen");
    player_names.append("Rex");
    req_body["playerNames"] = player_names;

    auto req = drogon::HttpRequest::newHttpJsonRequest(req_body);
    req->setMethod(drogon::HttpMethod::Post);
    req->setPath("/CreateGame/");

    auto res = client_->sendRequest(req);
    ASSERT_THAT(res.first, Eq(drogon::ReqResult::Ok));
    ASSERT_THAT(res.second, NotNull());

    auto res_status = (*res.second).getStatusCode();
    ASSERT_THAT(res_status, Eq(drogon::HttpStatusCode::k400BadRequest));

    auto& res_body = *((*res.second).getJsonObject());
    ASSERT_THAT(res_body["Message"].asString(), StrNe(""));
}

TEST_F(TestCreateGame, Given_When4PlayersJoinTheGame_ThenSuccessToCreateGame)
{
    Json::Value req_body;
    Json::Value player_names(Json::arrayValue);
    player_names.append("Himmel");
    player_names.append("Frieren");
    player_names.append("Heiter");
    player_names.append("Eisen");
    req_body["playerNames"] = player_names;

    auto req = drogon::HttpRequest::newHttpJsonRequest(req_body);
    req->setMethod(drogon::HttpMethod::Post);
    req->setPath("/CreateGame/");

    auto res = client_->sendRequest(req);
    ASSERT_THAT(res.first, Eq(drogon::ReqResult::Ok));
    ASSERT_THAT(res.second, NotNull());

    auto res_status = (*res.second).getStatusCode();
    ASSERT_THAT(res_status, Eq(drogon::HttpStatusCode::k200OK));

    auto& res_body = *((*res.second).getJsonObject());
    ASSERT_THAT(res_body["Message"].asString(), StrNe(""));
    ASSERT_THAT(res_body["GameID"].asString(), StrNe(""));
    game_id_ = res_body["GameID"].asString();
}