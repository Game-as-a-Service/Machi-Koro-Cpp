#include "amusement_park.h"

AmusementPark::AmusementPark() :
    Landmark(CardName::AMUSEMENT_PARK, 16, CardType::MAJOR_ESTABLISHMENT)
{
}

void AmusementPark::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}