#ifndef AMUSEMENTPARK_H
#define AMUSEMENTPARK_H

#include "landmark.h"

class AmusementPark : public Landmark {
public:
    AmusementPark();

    ~AmusementPark() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif