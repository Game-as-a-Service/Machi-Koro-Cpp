#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <drogon/drogon.h>
#include <drogon/HttpTypes.h>

#include <string>

#include "test_def.h"
#include "repos/repository.h"
#include "repos/memory_repository.h"
#include "models/machikoro_game.h"
#include "tests/mock_objects/mock_dice.h"

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

        // // Repo.
        Repository& repo_ = MemoryRepository::self();
        MachiKoroGame* game = repo_.findById(game_id_);

        // InitGame
        Json::Value init_game_req_body;

        auto init_req = drogon::HttpRequest::newHttpJsonRequest(init_game_req_body);
        init_req->setMethod(drogon::HttpMethod::Post);
        init_req->setPath("/InitGame/" + game_id_);

        auto init_res = client_->sendRequest(init_req);
        ASSERT_THAT(init_res.first, Eq(drogon::ReqResult::Ok));
        ASSERT_THAT(init_res.second, NotNull());

        auto init_res_status = (*init_res.second).getStatusCode();
        ASSERT_THAT(init_res_status, Eq(drogon::HttpStatusCode::k200OK));

        auto& init_res_body = *((*init_res.second).getJsonObject());
        ASSERT_THAT(init_res_body["NextPlayerName"].asString(), StrNe(""));

        next_player_name = init_res_body["NextPlayerName"].asString();

        bank_balance_after_init = std::stoi(init_res_body["BankBalance"].asString());
        player_coin_after_init = std::stoi(init_res_body["Players"][0]["Money"].asString());

        // Give mock dice to game.
        std::unique_ptr<MockDice> dice = std::make_unique<MockDice>();
        dice_ = dice.get();
        game->set_dice(std::move(dice));
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

            game_id_.clear();
        }
    }

    // Repo.
    Repository& repo_ = MemoryRepository::self();

    // Client.
    drogon::HttpClientPtr client_ = drogon::HttpClient::newHttpClient(HTTP_ADDR);

    // Current Game ID in each test cases.
    std::string game_id_;

    std::string next_player_name;

    MockDice* dice_ = nullptr;

    int bank_balance_after_init = 0;

    int player_coin_after_init = 0;
};

TEST_F(TestRollDice, Given_WhenOnePlayerRollDice_ThenOperateCardEffect)
{
    // Given game init finished. The current player only has 1 wheat field card and
    // one bakery.
    Json::Value req_body;
    req_body["playerName"] = next_player_name;
    req_body["diceCount"] = 1;

    auto req = drogon::HttpRequest::newHttpJsonRequest(req_body);
    req->setMethod(drogon::HttpMethod::Post);
    req->setPath("/RollDice/" + game_id_);

    // The player roll dice and get 2 (bakery operate effect, gain one coin from bank).
    EXPECT_CALL(*dice_, generatePoint()).WillOnce(testing::Return(2));

    auto res = client_->sendRequest(req);
    ASSERT_THAT(res.first, Eq(drogon::ReqResult::Ok));
    ASSERT_THAT(res.second, NotNull());

    auto res_status = (*res.second).getStatusCode();
    ASSERT_THAT(res_status, Eq(drogon::HttpStatusCode::k200OK));

    auto& res_body = *((*res.second).getJsonObject());
    ASSERT_THAT(res_body["Message"].asString(), StrNe(""));
    EXPECT_THAT(std::stoi(res_body["BankBalance"].asString()), Eq(bank_balance_after_init - 1));
    //Find the player whose name is next_player_name, and get the coin
    for (auto& player : res_body["Players"])
    {
        if (player["Name"].asString() == next_player_name) {
            EXPECT_THAT(std::stoi(player["Money"].asString()), Eq(player_coin_after_init + 1));
        } else {
            EXPECT_THAT(std::stoi(player["Money"].asString()), Eq(player_coin_after_init));
        }
    }
}
