#ifndef TVSTATION_H
#define TVSTATION_H

#include "building.h"

class TvStation : public Building {
public:
    TvStation();
    ~TvStation() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif