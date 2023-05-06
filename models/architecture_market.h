#ifndef ARCHITECTURE_MARKET_H
#define ARCHITECTURE_MARKET_H

#include <map>
#include <vector>

#include "./card/card.h"
#include "./card/landmark.h"
#include "./card/initial_building.h"

class ArchitectureMarket {
public:
    ArchitectureMarket();
    ArchitectureMarket(const ArchitectureMarket& market) = delete;
    ArchitectureMarket(ArchitectureMarket&& market) = delete;
    ~ArchitectureMarket();

    ArchitectureMarket& operator = (const ArchitectureMarket& rhs) = delete;
    ArchitectureMarket& operator = (ArchitectureMarket&& rhs) = delete;

    Card DrawBuilding();

    Card DrawLandmark();

    Card DrawInitialBuilding();
    
private:
    std::map<int, Card> buildings_;
    std::vector<Landmark> landmarks_;
    std::vector<InitialBuilding> important_buildings_;
};

#endif