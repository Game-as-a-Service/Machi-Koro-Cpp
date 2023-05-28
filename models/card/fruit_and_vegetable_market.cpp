#include "fruit_and_vegetable_market.h"

FruitAndVegetableMarket::FruitAndVegetableMarket() :  
    Building(CardName::FRUIT_AND_VEGETABLE_MARKET, 2, CardType::FACTORY_OR_MARKET, {11,12}, IndustryType::SECONDARY_INDUSTRY)
{
}

void FruitAndVegetableMarket::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}