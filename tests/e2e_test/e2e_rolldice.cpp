#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <drogon/drogon.h>
#include <drogon/HttpTypes.h>

#include <string>

#include "test_def.h"
#include "repos/repository.h"
#include "repos/memory_repository.h"
#include "models/machikoro_game.h"
#include "models/tests/mock_dice.h"

using ::testing::Eq;
using ::testing::NotNull;
using ::testing::StrNe;

class TestRollDice : public ::testing::Test {
protected:
    void SetUp() override
    {
        // Create game with 4 players.
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

        // Assign Mock dice to the player
        // // Repo.
        Repository& repo_ = MemoryRepository::self();
        MachiKoroGame* game = repo_.findById(game_id_);
        // Give mock dice to game. Add a set_dice to game, and add it in createGame usecase
        game->set_dice(std::move(std::make_unique<MockDice>()));

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

TEST_F(TestRollDice, Given_WhenOnePlayerRollDice_ThenOperateCardEffect)
{

}