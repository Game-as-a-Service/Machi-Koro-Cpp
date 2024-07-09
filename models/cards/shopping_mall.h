#ifndef SHOPPINGMALL_H
#define SHOPPINGMALL_H

#include "landmark.h"

class ShoppingMall : public Landmark {
public:
    ShoppingMall();

    ~ShoppingMall() = default;

    void operateEffect(Player* owner,
                       Player* dice_roller,
                       int point,
                       std::vector<Player*> players,
                       Bank* bank,
                       IndustryType curr_industry_type) override;
};

#endif