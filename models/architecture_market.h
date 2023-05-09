#ifndef ARCHITECTURE_MARKET_H
#define ARCHITECTURE_MARKET_H

#include <map>
#include <string>
#include <vector>
#include <deque>
#include <memory>

#include "./card/card.h"
#include "./card/landmark.h"

class ArchitectureMarket {
#include "./card/building.h"
    ~ArchitectureMarket();

    ArchitectureMarket& operator = (const ArchitectureMarket& rhs) = delete;
    ArchitectureMarket& operator = (ArchitectureMarket&& rhs) = delete;

    //Card DrawBuilding();

    //Card DrawLandmark();

    //Card DrawInitialBuilding();
    
private:
    std::vector<std::shared_ptr<Card>> landmarks_;
    std::vector<std::shared_ptr<Card>> initial_buildings_;
    // key: Card name; Value : Cards.
    std::map<std::string, std::deque<std::shared_ptr<Card>>> buildings_;
};

#endif