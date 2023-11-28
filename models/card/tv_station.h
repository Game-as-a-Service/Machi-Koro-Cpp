#ifndef TVSTATION_H
#define TVSTATION_H

#include "building.h"

class TvStation : public Building {
public:
    TvStation();
    ~TvStation() = default;

    void OperateEffect(Player* owner,
        Player* dice_roller,
        std::vector<Player*> players,
        Bank* bank) override;
};

#endif