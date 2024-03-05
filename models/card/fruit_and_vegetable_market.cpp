#include "fruit_and_vegetable_market.h"

FruitAndVegetableMarket::FruitAndVegetableMarket() :
    Building(CardName::FRUIT_AND_VEGETABLE_MARKET, 2, CardType::FACTORY_OR_MARKET, {11,12}, IndustryType::SECONDARY_INDUSTRY)
{
}

void FruitAndVegetableMarket::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}