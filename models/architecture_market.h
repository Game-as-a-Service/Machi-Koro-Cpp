#ifndef ARCHITECTURE_MARKET_H
#define ARCHITECTURE_MARKET_H

#include <map>
#include <string>
#include <vector>
#include <deque>
#include <memory>

#include "./card/card.h"
#include "./card/landmark.h"
#include "./card/building.h"

class ArchitectureMarket {
public:
    ArchitectureMarket();
    ~ArchitectureMarket();

    ArchitectureMarket& operator = (const ArchitectureMarket& rhs) = delete;
    ArchitectureMarket& operator = (ArchitectureMarket&& rhs) = delete;

    std::vector<std::unique_ptr<Card>> GetInitialBuildingsForOnePlayer();
    std::vector<std::unique_ptr<Card>> GetLandmarksForOnePlayer();
    
    const std::map<CardName, std::deque<std::unique_ptr<Card>>>& get_buildings() const { return buildings_; }
     
    //Card DrawBuilding();
    //Card DrawLandmark();
    //Card DrawInitialBuilding();
    
private:
    // key: Card name; Value : Cards.
    std::map<CardName, std::deque<std::unique_ptr<Card>>> buildings_;

};

#endif