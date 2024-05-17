#include "family_restaurant.h"

#include "models/bank.h"
#include "models/player.h"

FamilyRestaurant::FamilyRestaurant()
    : Building(CardName::FAMILY_RESTAURANT,
               CardType::RESTAURANT,
               3,
               IndustryType::IMPORTANT_BUILDING,
               { 9, 10 })
{
}

void FamilyRestaurant::OperateEffect(Player* owner,
                                     Player* dice_roller,
                                     std::vector<Player*> players,
                                     std::shared_ptr<Bank> bank)
{
}