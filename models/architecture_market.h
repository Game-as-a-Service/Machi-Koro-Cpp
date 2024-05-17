#ifndef MODELS_ARCHITECTURE_MARKET_H
#define MODELS_ARCHITECTURE_MARKET_H

#include <map>
#include <memory>
#include <functional>
#include <optional>

#include "cards/building.h"

class ArchitectureMarket {
public:
    ArchitectureMarket();

    // Non-copyable.
    ArchitectureMarket(const ArchitectureMarket& other) = delete;
    ArchitectureMarket& operator=(const ArchitectureMarket& other) = delete;

    ~ArchitectureMarket() = default;

    std::optional<BuildingPtr> drawCard(CardName name);

    std::map<CardName, int> cards() const;

private:
    // All the building cards.
    std::map<CardName, BuildingPtrs> cards_;
};

#endif  // MODELS_ARCHITECTURE_MARKET_H