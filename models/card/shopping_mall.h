#ifndef SHOPPINGMALL_H
#define SHOPPINGMALL_H

#include "landmark.h"

class ShoppingMall : public Landmark{
public:
    ShoppingMall();
    ~ShoppingMall() = default;

    void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) override;
    
};

#endif