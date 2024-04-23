#ifndef MODELS_ARCHITECTURE_MARKET_H
#define MODELS_ARCHITECTURE_MARKET_H

#include <map>
#include <memory>
#include <functional>

#include "cards/building.h"

class ArchitectureMarket {
public:
    ArchitectureMarket();

    // Non-copyable.
    ArchitectureMarket(const ArchitectureMarket& other) = delete;
    ArchitectureMarket& operator=(const ArchitectureMarket& other) = delete;

    ~ArchitectureMarket() = default;

    BuildingPtr drawCard(const CardName& name);

    std::map<CardName, std::vector<Building*>> cards() const;

private:
    // All the building cards.
    std::map<CardName, BuildingPtrs> cards_;
};

#endif  // MODELS_ARCHITECTURE_MARKET_H