#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <memory>

#include "models/bank.h"
#include "models/dice.h"
#include "models/player.h"
#include "models/cards/wheat_field.h"

class OperateEffectTest: public ::testing::Test {
public:
    static const int initial_coin;
    static const int bank_initial_coin;

protected:
    virtual void SetUp() override {
        // Ensure all players have enough coins.
        bank = std::make_shared<Bank>();
        auto dice = std::make_shared<Dice>();
        card_owner = new Player("card owner", dice);
        dice_roller = new Player("dice roller", dice);
        player_1 = new Player("player 1", dice);
        player_2 = new Player("plaeyr 2", dice);

        card_owner->gainCoin(OperateEffectTest::initial_coin);
        dice_roller->gainCoin(OperateEffectTest::initial_coin);
        player_1->gainCoin(OperateEffectTest::initial_coin);
        player_2->gainCoin(OperateEffectTest::initial_coin);
        std::vector<Player*> players = {card_owner, dice_roller, player_1, player_2};
    }

    virtual void TearDown() override {
        bank.reset();

        delete card_owner;
        card_owner = nullptr;

        delete dice_roller;
        dice_roller = nullptr;

        delete player_1;
        player_1 = nullptr;

        delete player_2;
        player_2 = nullptr;
    }

    std::shared_ptr<Bank> bank = nullptr;
    Player* card_owner = nullptr;
    Player* dice_roller = nullptr;
    Player* player_1 = nullptr;
    Player* player_2 = nullptr;
    std::vector<Player*> players;
};

const int OperateEffectTest::initial_coin = 100;
const int OperateEffectTest::bank_initial_coin = 282;

// Primary industry
TEST_F(OperateEffectTest, WheatFieldNormalCase) {
    // You can get 1 coin from the bank, if the dice value is 1.
    WheatField card;
    card.OperateEffect(card_owner, dice_roller, players, bank);
    EXPECT_EQ(card_owner->totalCoin(), OperateEffectTest::initial_coin + 1);
    EXPECT_EQ(dice_roller->totalCoin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(player_1->totalCoin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(player_2->totalCoin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(bank->totalCoin(), OperateEffectTest::bank_initial_coin - 1);
}
