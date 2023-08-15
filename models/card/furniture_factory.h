#ifndef FURNITUREFACTORY_H
#define FURNITUREFACTORY_H

#include "building.h"

class FurnitureFactory : public Building {
public:
    FurnitureFactory();
    ~FurnitureFactory() = default;
    
    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif