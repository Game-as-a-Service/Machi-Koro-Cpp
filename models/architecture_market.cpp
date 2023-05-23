#include "architecture_market.h"

#include <cassert>

ArchitectureMarket::ArchitectureMarket()
{
    // Create 84 Architecture Cards.(12 important _buildings, 72 general buildings)
    // 8 initial_buildings, 16 landmarks
    
    
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
    assert(buildings_[CardName::RANCH].size() > 0 && "There is no ranch card in the market.");   
    cards.push_back(buildings_[CardName::WHEAT_FIELD].back());
    cards.push_back(buildings_[CardName::RANCH].back());
    buildings_[CardName::WHEAT_FIELD].pop_back();
    buildings_[CardName::RANCH].pop_back();
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