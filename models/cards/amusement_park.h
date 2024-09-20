#ifndef AMUSEMENTPARK_H
#define AMUSEMENTPARK_H

#include "landmark.h"

class AmusementPark : public Landmark {
public:
    AmusementPark();

    ~AmusementPark() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       int point,
                       std::vector<Player*> players,
                       Bank* bank,
                       IndustryType curr_industry_type);
};

#endif