#include "shopping_mall.h"

#include "models/bank.h"
#include "models/player.h"

ShoppingMall::ShoppingMall()
    : Landmark(CardName::SHOPPING_MALL, CardType::MAJOR_ESTABLISHMENT, 10)
{
}

void ShoppingMall::operateEffect(Player* owner,
                       Player* dice_roller,
                       int point,
                       std::vector<Player*> players,
                       Bank* bank,
                       IndustryType curr_industry_type)
{
}