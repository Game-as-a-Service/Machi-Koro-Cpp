#ifndef MODELS_HAND_H
#define MODELS_HAND_H

#include <vector>

#include "cards/landmark.h"
#include "cards/building.h"

class Hand {
public:
    Hand();

    Hand(LandmarkPtrs&& landmarks, BuildingPtrs&& buildings);

    // Non-copyable.
    Hand(const Hand& other) = delete;
    Hand& operator=(const Hand& other) = delete;

    ~Hand() = default;

    void gainCard(BuildingPtr&& building);

    std::vector<Landmark*> landmarks() const;

    std::vector<Building*> buildings() const;

private:
    LandmarkPtrs landmarks_;

    BuildingPtrs buildings_;
};

#endif  // MODELS_HAND_H