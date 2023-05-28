#ifndef CONVENIENSTORE_H
#define CONVENIENSTORE_H

#include "building.h"

class ConvenientStore : public Building {
public:
    ConvenientStore();
    ~ConvenientStore() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;

};

#endif