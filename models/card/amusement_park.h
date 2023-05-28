#ifndef AMUSEMENTPARK_H
#define AMUSEMENTPARK_H

#include "landmark.h"

class AmusementPark : public Landmark {
public:
    AmusementPark();
    ~AmusementPark() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif