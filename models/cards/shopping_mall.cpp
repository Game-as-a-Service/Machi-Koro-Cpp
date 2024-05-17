#include "shopping_mall.h"

#include "models/bank.h"
#include "models/player.h"

ShoppingMall::ShoppingMall()
    : Landmark(CardName::SHOPPING_MALL, CardType::MAJOR_ESTABLISHMENT, 10)
{
}

void ShoppingMall::OperateEffect(Player* owner,
                                 Player* dice_roller,
                                 std::vector<Player*> players,
                                 std::shared_ptr<Bank> bank)
{
}