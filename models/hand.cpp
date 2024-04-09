#include "hand.h"

#include "cards/radio_tower.h"
#include "cards/train_station.h"
#include "cards/shopping_mall.h"
#include "cards/amusement_park.h"

Hand::Hand()
{
    landmarks_.push_back(std::make_unique<RadioTower>());
    landmarks_.push_back(std::make_unique<TrainStation>());
    landmarks_.push_back(std::make_unique<ShoppingMall>());
    landmarks_.push_back(std::make_unique<AmusementPark>());
}

Hand::Hand(LandmarkPtrs&& landmarks, BuildingPtrs&& buildings)
    : landmarks_(std::move(landmarks))
    , buildings_(std::move(buildings))
{
}

void Hand::gainCard(BuildingPtr card)
{
    buildings_.push_back(std::move(card));
}

std::vector<Landmark*> Hand::landmarks() const
{
    std::vector<Landmark*> res;
    for (auto& card : landmarks_) res.push_back(card.get());
    return res;
}

std::vector<Building*> Hand::buildings() const
{
    std::vector<Building*> res;
    for (auto& card : buildings_) res.push_back(card.get());
    return res;
}