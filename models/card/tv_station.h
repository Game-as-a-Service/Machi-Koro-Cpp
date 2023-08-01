#ifndef TVSTATION_H
#define TVSTATION_H

#include "building.h"

class TvStation : public Building {
public:
    TvStation();
    ~TvStation() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif