#include "architecture_market.h"

#include <cassert>

#include "wheat_field.h"
#include "ranch.h"
#include "bakery.h"
#include "cafe.h"
#include "convenient_store.h"
#include "forest.h"
#include "stadium.h"
#include "tv_station.h"
#include "business_center.h"
#include "cheese_factory.h"
#include "furniture_factory.h"
#include "mine.h"
#include "family_restaurant.h"
#include "apple_orchard.h"
#include "fruit_and_vegetable_market.h"
#include "amusement_park.h"
#include "radio_tower.h"
#include "shopping_mall.h"
#include "train_station.h"

ArchitectureMarket::ArchitectureMarket()
{
    auto addBuildings = [&](const CardName& name, auto building, const int count) {
        for (int i = 0; i < count; ++i) {
            buildings_[name].push_back(std::make_shared<decltype(building)>());
        }
    };
    
    // Buildings.
    addBuildings(CardName::WHEAT_FIELD, WheatField{}, 10);
    addBuildings(CardName::RANCH, Ranch{}, 6);
    addBuildings(CardName::BAKERY, Bakery{}, 10);
    addBuildings(CardName::CAFE, Cafe{}, 6);
    addBuildings(CardName::CONVENIENCE_STORE, ConvenientStore{}, 6);
    addBuildings(CardName::FOREST, Forest{}, 6);
    addBuildings(CardName::STADIUM, Stadium{}, 4);
    addBuildings(CardName::TV_STATION, TvStation{}, 4);
    addBuildings(CardName::BUSINESS_CENTER, BusinessCenter{}, 4);
    addBuildings(CardName::CHEESE_FACTORY, CheeseFactory{}, 6);
    addBuildings(CardName::FURNITURE_FACTORY, FurnitureFactory{}, 6);
    addBuildings(CardName::MINE, Mine{}, 6);
    addBuildings(CardName::FAMILY_RESTAURANT, FamilyRestaurant{}, 6);
    addBuildings(CardName::APPLE_ORCHARD, AppleOrchard{}, 6);
    addBuildings(CardName::FRUIT_AND_VEGETABLE_MARKET, FruitAndVegetableMarket{}, 6);

    // Landmarks.
    addBuildings(CardName::AMUSEMENT_PARK, AmusementPark{}, 4);
    addBuildings(CardName::RADIO_TOWER, RadioTower{}, 4);
    addBuildings(CardName::SHOPPING_MALL, ShoppingMall{}, 4);
    addBuildings(CardName::TRAIN_STATION, TrainStation{}, 4);
    
}

ArchitectureMarket::~ArchitectureMarket()
{
    for (auto& cards : buildings_)
        for (auto& c : cards.second) c = nullptr;
    buildings_.clear();
}

std::vector<std::shared_ptr<Card>> ArchitectureMarket::GetInitialBuildingsForOnePlayer()
{
    // 每個玩家一開始都各持有一張小麥田和麵包店。
    std::vector<std::shared_ptr<Card>> cards;
    assert(buildings_[CardName::WHEAT_FIELD].size() > 0 && "There is no wheat field card in the market.");   
    assert(buildings_[CardName::BAKERY].size() > 0 && "There is no bakery card in the market.");   
    cards.push_back(buildings_[CardName::WHEAT_FIELD].back());
    cards.push_back(buildings_[CardName::BAKERY].back());
    buildings_[CardName::WHEAT_FIELD].pop_back();
    buildings_[CardName::BAKERY].pop_back();
    return cards;
}

std::vector<std::shared_ptr<Card>> ArchitectureMarket::GetLandmarksForOnePlayer()
{
    // 每個玩家一開始各分到一張主題樂園、一張廣播電台、一張購物中心，以及一張火車站。
    std::vector<std::shared_ptr<Card>> cards;
    assert(buildings_[CardName::AMUSEMENT_PARK].size() > 0 && "There is no amusement park card in the market.");
    assert(buildings_[CardName::SHOPPING_MALL].size() > 0 && "There is no shopping mall card in the market.");
    assert(buildings_[CardName::TRAIN_STATION].size() > 0 && "There is no train station card in the market.");
    assert(buildings_[CardName::RADIO_TOWER].size() > 0 && "There is no radio tower card in the market.");
    cards.push_back(buildings_[CardName::AMUSEMENT_PARK].back());
    cards.push_back(buildings_[CardName::SHOPPING_MALL].back());
    cards.push_back(buildings_[CardName::TRAIN_STATION].back());
    cards.push_back(buildings_[CardName::RADIO_TOWER].back());
    buildings_[CardName::AMUSEMENT_PARK].pop_back();
    buildings_[CardName::SHOPPING_MALL].pop_back();
    buildings_[CardName::TRAIN_STATION].pop_back();
    buildings_[CardName::RADIO_TOWER].pop_back();
    return cards;
}