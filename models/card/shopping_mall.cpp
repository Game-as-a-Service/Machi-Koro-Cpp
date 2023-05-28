#include "shopping_mall.h"

ShoppingMall::ShoppingMall() : 
    Landmark(CardName::SHOPPING_MALL, 10, CardType::MAJOR_ESTABLISHMENT)
{
}

void ShoppingMall::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}