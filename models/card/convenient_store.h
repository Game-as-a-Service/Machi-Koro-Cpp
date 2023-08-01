#ifndef CONVENIENSTORE_H
#define CONVENIENSTORE_H

#include "building.h"

class ConvenientStore : public Building {
public:
    ConvenientStore();
    ~ConvenientStore() = default;

    void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) override;

};

#endif