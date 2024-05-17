#ifndef CONVENIENSTORE_H
#define CONVENIENSTORE_H

#include "building.h"

class ConvenientStore : public Building {
public:
    ConvenientStore();

    ~ConvenientStore() = default;

    void OperateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       std::shared_ptr<Bank> bank) override;
};

#endif