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

    std::vector<std::unique_ptr<Building>> GetInitialBuildingsForOnePlayer();
    std::vector<std::unique_ptr<Landmarks>> GetLandmarksForOnePlayer();

    const std::map<CardName, std::deque<std::unique_ptr<Building>>>&
    get_buildings() const { return buildings_; }

private:
    // key: Card name; Value : Cards.
    std::map<CardName, std::deque<std::unique_ptr<Building>>> buildings_;
    std::map<CardName, std::deque<std::unique_ptr<Landmark>>> landmarks_;
};

#endif