#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <memory>

#include "models/bank.h"
#include "models/dice.h"
#include "models/player.h"
#include "models/cards/bakery.h"

class OperateEffectTest: public ::testing::Test {
public:
    static const int initial_coin;
    static const int bank_initial_coin;

protected:
    virtual void SetUp() override {
        // Ensure all players have enough coins.
        bank_ = new Bank();
        card_owner_ = new Player("card owner");
        dice_roller_ = new Player("dice roller");
        player_1_ = new Player("player 1");
        player_2_ = new Player("plaeyr 2");

        card_owner_->gainCoin(OperateEffectTest::initial_coin);
        dice_roller_->gainCoin(OperateEffectTest::initial_coin);
        player_1_->gainCoin(OperateEffectTest::initial_coin);
        player_2_->gainCoin(OperateEffectTest::initial_coin);
        std::vector<Player*> players_ = {card_owner_, dice_roller_, player_1_, player_2_};
    }

    virtual void TearDown() override {
        delete bank_;
        bank_ = nullptr;

        delete card_owner_;
        card_owner_ = nullptr;

        delete dice_roller_;
        dice_roller_ = nullptr;

        delete player_1_;
        player_1_ = nullptr;

        delete player_2_;
        player_2_ = nullptr;
    }

    Bank* bank_ = nullptr;
    Player* card_owner_ = nullptr;
    Player* dice_roller_ = nullptr;
    Player* player_1_ = nullptr;
    Player* player_2_ = nullptr;
    std::vector<Player*> players_;
};

const int OperateEffectTest::initial_coin = 100;
const int OperateEffectTest::bank_initial_coin = 282;

// Primary industry
TEST_F(OperateEffectTest, BakeryNormalCase) {
    // You can get 1 coin from the bank, if the dice value is 2 or 3.
    Bakery bakery;
    bakery.doOperateEffect(card_owner_, dice_roller_, players_, bank_);
    EXPECT_EQ(card_owner_->totalCoin(), OperateEffectTest::initial_coin + 1);
    EXPECT_EQ(dice_roller_->totalCoin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(player_1_->totalCoin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(player_2_->totalCoin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(bank_->totalCoin(), OperateEffectTest::bank_initial_coin - 1);
}
