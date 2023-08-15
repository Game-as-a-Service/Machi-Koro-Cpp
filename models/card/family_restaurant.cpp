#include "family_restaurant.h"

FamilyRestaurant::FamilyRestaurant() : 
    Building(CardName::FAMILY_RESTAURANT, 3, CardType::RESTAURANT, {9, 10}, IndustryType::IMPORTANT_BUILDING)
{
}

void FamilyRestaurant::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{

}