#include "utils/util.h"

#include "drogon/utils/Utilities.h"
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

Util::Util()
{
    building_generators_[CardName::WHEAT_FIELD] = &generateBuildingsTemp<WheatField>;
    building_generators_[CardName::RANCH] = &generateBuildingsTemp<Ranch>;
    building_generators_[CardName::BAKERY] = &generateBuildingsTemp<Bakery>;
    building_generators_[CardName::CAFE] = &generateBuildingsTemp<Cafe>;
    building_generators_[CardName::CONVENIENCE_STORE] = &generateBuildingsTemp<ConvenientStore>;
    building_generators_[CardName::FOREST] = &generateBuildingsTemp<Forest>;
    building_generators_[CardName::STADIUM] = &generateBuildingsTemp<Stadium>;
    building_generators_[CardName::TV_STATION] = &generateBuildingsTemp<TvStation>;
    building_generators_[CardName::BUSINESS_CENTER] = &generateBuildingsTemp<BusinessCenter>;
    building_generators_[CardName::CHEESE_FACTORY] = &generateBuildingsTemp<CheeseFactory>;
    building_generators_[CardName::FURNITURE_FACTORY] = &generateBuildingsTemp<FurnitureFactory>;
    building_generators_[CardName::MINE] = &generateBuildingsTemp<Mine>;
    building_generators_[CardName::FAMILY_RESTAURANT] = &generateBuildingsTemp<FamilyRestaurant>;
    building_generators_[CardName::APPLE_ORCHARD] = &generateBuildingsTemp<AppleOrchard>;
    building_generators_[CardName::FRUIT_AND_VEGETABLE_MARKET] =
        &generateBuildingsTemp<FruitAndVegetableMarket>;
}

std::shared_ptr<Util> Util::self()
{
    static std::shared_ptr<Util> util(new Util);
    return util;
}

std::string Util::generateUUID() const
{
    return drogon::utils::getUuid();
}

BuildingPtrs Util::generateBuildings(const CardName& name, int num)
{
    return building_generators_[name](num);
}

std::string Util::getStringFromCardName(const CardName& name)
{
    static const std::map<CardName, std::string> cardNameStrings = {
        { CardName::WHEAT_FIELD, "Wheat Field" },
        { CardName::RANCH, "Ranch" },
        { CardName::BAKERY, "Bakery" },
        { CardName::CAFE, "Cafe" },
        { CardName::CONVENIENCE_STORE, "Convenient Store" },
        { CardName::FOREST, "Forest" },
        { CardName::STADIUM, "Stadium" },
        { CardName::TV_STATION, "TV Station" },
        { CardName::BUSINESS_CENTER, "Business Center" },
        { CardName::CHEESE_FACTORY, "Cheese Factory" },
        { CardName::FURNITURE_FACTORY, "Furniture Factory" },
        { CardName::MINE, "Mine" },
        { CardName::FAMILY_RESTAURANT, "Family Restaurant" },
        { CardName::APPLE_ORCHARD, "Apple Orchard" },
        { CardName::FRUIT_AND_VEGETABLE_MARKET, "Fruit and Vegetable Market" },
        { CardName::TRAIN_STATION, "Train Station"},
        { CardName::SHOPPING_MALL, "Shopping Mall"},
        { CardName::AMUSEMENT_PARK, "Amusement Park"},
        { CardName::RADIO_TOWER, "Radio Tower"}
    };

    auto it = cardNameStrings.find(name);
    if (it != cardNameStrings.end())
        return it->second;
    return "Unknown CardName";
}