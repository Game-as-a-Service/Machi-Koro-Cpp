#ifndef ARCHITECTURE_MARKET_H
#define ARCHITECTURE_MARKET_H

#include <vector>

#include "card.h"

class ArchitectureMarket {
public:
    ArchitectureMarket();
    ArchitectureMarket(const ArchitectureMarket& market) = delete;
    ArchitectureMarket(ArchitectureMarket&& market) = delete;
    ~ArchitectureMarket();

    ArchitectureMarket& operator = (const ArchitectureMarket& rhs) = delete;
    ArchitectureMarket& operator = (ArchitectureMarket&& rhs) = delete;

    Card DrawInitialBuilding();

    Card DrawLandmark();

    Card DrawBuilding();
    
private:
    std::vector<Card> cards_;

};

#endif