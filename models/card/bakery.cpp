#include "bakery.h"

Bakery::Bakery() :
    Building(CardName::BAKERY, 1, CardType::CROP, {2,3}, IndustryType::SECONDARY_INDUSTRY)
{
}

void Bakery::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}