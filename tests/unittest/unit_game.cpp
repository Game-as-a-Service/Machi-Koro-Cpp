#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

#include "utils/util.h"
#include "utils/util_base.h"
#include "loggers/logger.h"
#include "loggers/logger_base.h"
#include "models/machikoro_game.h"
#include "models/player.h"
#include "models/dice.h"

class GameTest : public ::testing::Test {
protected:
    std::unique_ptr<MachiKoroGame> game_;
    std::shared_ptr<LoggerBase> log_ = Logger::self();
    std::shared_ptr<UtilBase> util_ = Util::self();

    virtual void SetUp() override {
        // FIXME: Need to link 'Controller2Usecase'.
        game_ = std::make_unique<MachiKoroGame>(log_, util_);

        std::vector<std::string> names = {"Alice", "Bob", "Cindy", "David"};
        std::vector<PlayerPtr> players;
        for (const auto& name : names)
            players.emplace_back(std::make_unique<Player>(name));

        game_->createGame(std::move(players));
        game_->initGame();
    }

    virtual void TearDown() override {
        game_.reset();
    }
};

TEST_F(GameTest, GameInit) {
    ASSERT_TRUE(game_ != nullptr);
    ASSERT_EQ(game_->players()->size(), 4);
    EXPECT_EQ(game_->bank()->totalCoin(), 282 - 3 * 4);
    for (const auto& player : *game_->players()) {
        EXPECT_EQ(player->hand().buildings().size(), 2);
        EXPECT_EQ(player->hand().landmarks().size(), 4);
        EXPECT_EQ(player->totalCoin(), 3);
    }
    // 15 types of buildings (landmarks are not included)
    EXPECT_EQ(game_->market()->cards().size(), 15);
}