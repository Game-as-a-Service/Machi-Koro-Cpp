#ifndef CONVENIENSTORE_H
#define CONVENIENSTORE_H

#include "building.h"

class ConvenientStore : public Building {
public:
    ConvenientStore();

    ~ConvenientStore() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif