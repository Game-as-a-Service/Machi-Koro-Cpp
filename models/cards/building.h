#ifndef MODELS_CARDS_BUILDING_H
#define MODELS_CARDS_BUILDING_H

#include <vector>
#include <memory>

#include "card.h"

enum class IndustryType {
    RESTAURANT,
    SECONDARY_INDUSTRY,
    PRIMARY_INDUSTRY,
    IMPORTANT_BUILDING
};

class Building;
using BuildingPtr = std::unique_ptr<Building>;
using BuildingPtrs = std::vector<BuildingPtr>;

template<typename T>
BuildingPtrs generateBuildingsTemp(int count)
{
    std::vector<BuildingPtr> res;
    for (int i = 0; i < count; ++i) res.push_back(std::make_unique<T>());
    return res;
}

class Building : public Card {
public:
    Building(CardName name, CardType type, int price, IndustryType ind, std::vector<int>&& points);

    ~Building() = default;

    virtual void OperateEffect(Player* owner,
                               Player* dice_roller,
                               std::vector<Player*> others,
                               std::shared_ptr<Bank> bank) = 0;

    IndustryType industryType() const { return ind_type_; }

    std::vector<int> points() const { return points_; }

private:
    IndustryType ind_type_;

    std::vector<int> points_;
};

#endif  // MODELS_CARDS_BUILDING_H