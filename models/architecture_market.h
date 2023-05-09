#ifndef ARCHITECTURE_MARKET_H
#define ARCHITECTURE_MARKET_H

#include <map>
#include <vector>
#include <string>
#include <memory>

#include "./card/card.h"
#include "./card/landmark.h"
#include "./card/building.h"

class ArchitectureMarket {
public:
    ArchitectureMarket();
    ArchitectureMarket(const ArchitectureMarket& market) = delete;
    ArchitectureMarket(ArchitectureMarket&& market) = delete;
    ~ArchitectureMarket();

    ArchitectureMarket& operator = (const ArchitectureMarket& rhs) = delete;
    ArchitectureMarket& operator = (ArchitectureMarket&& rhs) = delete;

    //Card DrawBuilding();

    //Card DrawLandmark();

    //Card DrawInitialBuilding();
    
private:
    std::vector<std::shared_ptr<Card>> landmarks_;
    std::vector<std::shared_ptr<Card>> initial_buildings_;
    std::map<std::string, std::vector<std::shared_ptr<Card>>> buildings_;
};

#endif