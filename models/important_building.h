#ifndef IMPORTANT_BUILDING_H
#define IMPORTANT_BUILDING_H

#include "building.h"

class ImportantBuilding : public Building {
public:
    ImportantBuilding();
    ~ImportantBuilding();

    virtual void OperateEffect() = 0;

    void set_price(int price) { price_ = price; }
    int get_price() const { return price_; }

private:
    int price_ = 0;
};

#endif