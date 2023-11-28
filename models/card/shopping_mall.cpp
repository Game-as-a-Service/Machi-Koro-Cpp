#include "shopping_mall.h"

ShoppingMall::ShoppingMall() :
    Landmark(CardName::SHOPPING_MALL, 10, CardType::MAJOR_ESTABLISHMENT)
{
}

void ShoppingMall::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}