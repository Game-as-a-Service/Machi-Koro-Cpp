#include "architecture_market.h"

#include <cassert>

#include "card/wheat_field.h"
#include "card/ranch.h"
#include "card/bakery.h"
#include "card/cafe.h"
#include "card/convenient_store.h"
#include "card/forest.h"
#include "card/stadium.h"
#include "card/tv_station.h"
#include "card/business_center.h"
#include "card/cheese_factory.h"
#include "card/furniture_factory.h"
#include "card/mine.h"
#include "card/family_restaurant.h"
#include "card/apple_orchard.h"
#include "card/fruit_and_vegetable_market.h"
#include "card/amusement_park.h"
#include "card/radio_tower.h"
#include "card/shopping_mall.h"
#include "card/train_station.h"

ArchitectureMarket::ArchitectureMarket()
{
    auto addBuildings = [&](const CardName& name, auto building, const int count) {
        for (int i = 0; i < count; ++i) {
            buildings_[name].push_back(std::make_unique<decltype(building)>());
        }
    };
    auto addLandmarks= [&](const CardName& name, auto building, const int count) {
        for (int i = 0; i < count; ++i) {
            landmarks_[name].push_back(std::make_unique<decltype(building)>());
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
    addLandmarks(CardName::AMUSEMENT_PARK, AmusementPark{}, 4);
    addLandmarks(CardName::RADIO_TOWER, RadioTower{}, 4);
    addLandmarks(CardName::SHOPPING_MALL, ShoppingMall{}, 4);
    addLandmarks(CardName::TRAIN_STATION, TrainStation{}, 4);
}

ArchitectureMarket::~ArchitectureMarket()
{
    for (auto& cards : buildings_)
        for (auto& c : cards.second) c = nullptr;
    buildings_.clear();

    for (auto& cards : landmarks_)
        for (auto& c : cards.second) c = nullptr;
    landmarks_.clear();
}

std::vector<std::unique_ptr<Building>> ArchitectureMarket::GetInitialBuildingsForOnePlayer()
{
    // 每個玩家一開始都各持有一張小麥田和麵包店。
    std::vector<std::unique_ptr<Building>> cards;
    assert(buildings_[CardName::WHEAT_FIELD].size() > 0 && "There is no wheat field card in the market.");
    assert(buildings_[CardName::BAKERY].size() > 0 && "There is no bakery card in the market.");
    cards.push_back(std::move(buildings_[CardName::WHEAT_FIELD].back()));
    cards.push_back(std::move(buildings_[CardName::BAKERY].back()));
    buildings_[CardName::WHEAT_FIELD].pop_back();
    buildings_[CardName::BAKERY].pop_back();
    return cards;
}

std::vector<std::unique_ptr<Landmark>> ArchitectureMarket::GetLandmarksForOnePlayer()
{
    // 每個玩家一開始各分到一張主題樂園、一張廣播電台、一張購物中心，以及一張火車站。
    std::vector<std::unique_ptr<Landmark>> cards;
    assert(landmarks_[CardName::AMUSEMENT_PARK].size() > 0 &&
        "There is no amusement park card in the market.");
    assert(landmarks_[CardName::SHOPPING_MALL].size() > 0 &&
        "There is no shopping mall card in the market.");
    assert(landmarks_[CardName::TRAIN_STATION].size() > 0 &&
        "There is no train station card in the market.");
    assert(landmarks_[CardName::RADIO_TOWER].size() > 0 &&
        "There is no radio tower card in the market.");
    cards.push_back(std::move(landmarks_[CardName::AMUSEMENT_PARK].back()));
    cards.push_back(std::move(landmarks_[CardName::SHOPPING_MALL].back()));
    cards.push_back(std::move(landmarks_[CardName::TRAIN_STATION].back()));
    cards.push_back(std::move(landmarks_[CardName::RADIO_TOWER].back()));
    landmarks_[CardName::AMUSEMENT_PARK].pop_back();
    landmarks_[CardName::SHOPPING_MALL].pop_back();
    landmarks_[CardName::TRAIN_STATION].pop_back();
    landmarks_[CardName::RADIO_TOWER].pop_back();
    return cards;
}