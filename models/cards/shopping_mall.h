#ifndef SHOPPINGMALL_H
#define SHOPPINGMALL_H

#include "landmark.h"

class ShoppingMall : public Landmark {
public:
    ShoppingMall();

    ~ShoppingMall() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       std::vector<Player*> players,
                       Bank* bank) override;
};

#endif