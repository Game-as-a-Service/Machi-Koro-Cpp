#include "architecture_market.h"

ArchitectureMarket::ArchitectureMarket()
{
    // Create 84 Architecture Cards.(12 important _buildings, 72 general buildings)
    // 8 initial_buildings, 16 landmarks.
    
}

ArchitectureMarket::~ArchitectureMarket()
{
    for (auto& l : landmarks_) l = nullptr;
    landmarks_.clear();
    for (auto& b : initial_buildings_) b = nullptr;
    initial_buildings_.clear();
    for (auto& cards : buildings_)
        for (auto& c : cards.second) c = nullptr;
    buildings_.clear();
}