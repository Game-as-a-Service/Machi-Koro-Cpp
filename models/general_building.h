#ifndef GENERAL_BUILDING_H
#define GENERAL_BUILDING_H

#include "building.h"

class GeneralBuilding : public Building {
public:
    GeneralBuilding();
    ~GeneralBuilding();
    
    virtual void OperateEffect() = 0;

    void set_price(int price) { price_ = price; }
    int get_price() const { return price_; }

private:
    int price_ = 0;
};

#endif