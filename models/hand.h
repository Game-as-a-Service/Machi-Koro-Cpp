#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>

#include "card/card.h"
#include "card/building.h"
#include "card/landmark.h"

class Building;
class Landmark;

class Hand {
public:
    Hand();
    ~Hand();

    void AddBuilding(std::unique_ptr<Building> card) 
    { buildings_.push_back(std::move(card)); }

    void AddLandmark(std::unique_ptr<Landmark> card) 
    { landmarks_.push_back(std::move(card)); }

    std::vector<Building*> get_buildings() const;

    std::vector<Landmark*> get_landmarks() const;

private:
    std::vector<std::unique_ptr<Building>> buildings_;
    std::vector<std::unique_ptr<Landmark>> landmarks_;
};

#endif