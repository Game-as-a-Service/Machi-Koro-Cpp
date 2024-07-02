#include "fruit_and_vegetable_market.h"

#include "models/bank.h"
#include "models/player.h"

FruitAndVegetableMarket::FruitAndVegetableMarket()
    : Building(CardName::FRUIT_AND_VEGETABLE_MARKET,
               CardType::FACTORY_OR_MARKET,
               2,
               IndustryType::SECONDARY_INDUSTRY,
               { 11, 12 })
{
}

void FruitAndVegetableMarket::operateEffect(Player* owner,
                                            Player* dice_roller,
                                            std::vector<Player*> players,
                                            Bank* bank)
{
}