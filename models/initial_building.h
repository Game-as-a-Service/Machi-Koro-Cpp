#ifndef INITIAL_BUILDING_H
#define INITIAL_BUILDING_H

#include "building.h"

class InitialBuilding : public Building {
public:
    InitialBuilding();
    ~InitialBuilding();

    virtual void OperateEffect() = 0;

private:
    
};

#endif