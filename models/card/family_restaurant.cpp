#include "family_restaurant.h"

FamilyRestaurant::FamilyRestaurant() : 
    Building(CardName::FAMILY_RESTAURANT, 3, CardType::RESTAURANT, {9, 10}, IndustryType::IMPORTANT_BUILDING)
{
}

void FamilyRestaurant::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{

}