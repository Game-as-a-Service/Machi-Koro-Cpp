#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

#include "../../models/bank.h"
#include "../../models/player.h"
#include "../../models/card/wheat_field.h"

class OperateEffectTest: public ::testing::Test {
public:
    static const int initial_coin;
    static const int bank_initial_coin;

protected:
    virtual void SetUp() override {
        // Ensure all players have enough coins.
        bank = new Bank();
        card_owner = new Player();
        dice_roller = new Player();
        player_1 = new Player();
        player_2 = new Player();

        card_owner->GainCoin(OperateEffectTest::initial_coin);
        dice_roller->GainCoin(OperateEffectTest::initial_coin);
        player_1->GainCoin(OperateEffectTest::initial_coin);
        player_2->GainCoin(OperateEffectTest::initial_coin);
        std::vector<Player*> players = {card_owner, dice_roller, player_1, player_2};
    }

    virtual void TearDown() override {
        delete bank;
        bank = nullptr;

        delete card_owner;
        card_owner = nullptr;

        delete dice_roller;
        dice_roller = nullptr;

        delete player_1;
        player_1 = nullptr;

        delete player_2;
        player_2 = nullptr;
    }

    Bank* bank = nullptr;
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
    EXPECT_EQ(card_owner->get_coin(), OperateEffectTest::initial_coin + 1);
    EXPECT_EQ(dice_roller->get_coin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(player_1->get_coin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(player_2->get_coin(), OperateEffectTest::initial_coin);
    EXPECT_EQ(bank->get_coin(), OperateEffectTest::bank_initial_coin - 1);
}
