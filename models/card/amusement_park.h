#ifndef AMUSEMENTPARK_H
#define AMUSEMENTPARK_H

#include "landmark.h"

class AmusementPark : public Landmark {
public:
    AmusementPark();
    ~AmusementPark() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif