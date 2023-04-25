#ifndef LANDMARK_H
#define LANDMARK_H

#include "card.h"

class Landmark: public Card {
public:
    Landmark();
    ~Landmark();
    bool IsActivate();
    void Activate();
private:
    // False: 背面, True: 正面。
    bool isActivated_ = false;
};

#endif