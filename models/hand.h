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

    void gainCard(BuildingPtr building);

    /**
     * @brief Get the landmarks.
     * @note Since the return values are pointers, the caller can modify the landmarks.
     */
    std::vector<Landmark*> landmarks();

    /**
     * @brief Get the buildings.
     * @note Since the return values are pointers, the caller can modify the buildings.
     */
    std::vector<Building*> buildings();

private:
    LandmarkPtrs landmarks_;

    BuildingPtrs buildings_;
};

#endif  // MODELS_HAND_H