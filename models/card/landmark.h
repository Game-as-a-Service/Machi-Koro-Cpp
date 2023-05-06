#ifndef LANDMARK_H
#define LANDMARK_H

#include "card.h"

class Landmark: public Card {
public:
    Landmark();
    ~Landmark();

    virtual void OperateEffect() = 0;

    bool IsActivate();
    void Activate();

    void set_price(int price) { price_ = price; }
    int get_price() const { return price_; }

private:
    // False: 背面, True: 正面。
    bool isActivated_ = false;

    int price_ = 0;
};

#endif