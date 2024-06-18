#include "architecture_market.h"

#include "models/cards/wheat_field.h"
#include "models/cards/ranch.h"
#include "models/cards/bakery.h"
#include "models/cards/cafe.h"
#include "models/cards/convenient_store.h"
#include "models/cards/forest.h"
#include "models/cards/stadium.h"
#include "models/cards/tv_station.h"
#include "models/cards/business_center.h"
#include "models/cards/cheese_factory.h"
#include "models/cards/furniture_factory.h"
#include "models/cards/mine.h"
#include "models/cards/family_restaurant.h"
#include "models/cards/apple_orchard.h"
#include "models/cards/fruit_and_vegetable_market.h"
#include "models/cards/amusement_park.h"
#include "models/cards/radio_tower.h"
#include "models/cards/shopping_mall.h"
#include "models/cards/train_station.h"

ArchitectureMarket::ArchitectureMarket()
{
    cards_[CardName::WHEAT_FIELD] = generateBuildingsTemp<WheatField>(10);
    cards_[CardName::RANCH] = generateBuildingsTemp<Ranch>(6);
    cards_[CardName::BAKERY] = generateBuildingsTemp<Bakery>(10);
    cards_[CardName::CAFE] = generateBuildingsTemp<Cafe>(6);
    cards_[CardName::CONVENIENCE_STORE] = generateBuildingsTemp<ConvenientStore>(6);
    cards_[CardName::FOREST] = generateBuildingsTemp<Forest>(6);
    cards_[CardName::STADIUM] = generateBuildingsTemp<Stadium>(4);
    cards_[CardName::TV_STATION] = generateBuildingsTemp<TvStation>(4);
    cards_[CardName::BUSINESS_CENTER] = generateBuildingsTemp<BusinessCenter>(4);
    cards_[CardName::CHEESE_FACTORY] = generateBuildingsTemp<CheeseFactory>(6);
    cards_[CardName::FURNITURE_FACTORY] = generateBuildingsTemp<FurnitureFactory>(6);
    cards_[CardName::MINE] = generateBuildingsTemp<Mine>(6);
    cards_[CardName::FAMILY_RESTAURANT] = generateBuildingsTemp<FamilyRestaurant>(6);
    cards_[CardName::APPLE_ORCHARD] = generateBuildingsTemp<AppleOrchard>(6);
    cards_[CardName::FRUIT_AND_VEGETABLE_MARKET] =
        generateBuildingsTemp<FruitAndVegetableMarket>(6);
}

BuildingPtr ArchitectureMarket::drawCard(const CardName& name)
{
    auto res = std::move(cards_[name].back());
    cards_[name].pop_back();
    return res;
}

std::map<CardName, int> ArchitectureMarket::cards() const
{
    std::map<CardName, int> res;
    for (const auto& card : cards_)
    {
        res[card.first] = card.second.size();
    }
    return res;
}