#ifndef BUILDING_H
#define BUILDING_H

#include "card.h"

class Building : public Card {
public:
    Building();
    ~Building();

    virtual void OperateEffect() = 0;

    void set_points(int point) { points_ = point; }
    int get_points() const { return points_; }

private:
    int points_ = 1;

};

#endif