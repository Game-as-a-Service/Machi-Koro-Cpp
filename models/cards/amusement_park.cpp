#include "amusement_park.h"

#include "models/bank.h"
#include "models/player.h"

AmusementPark::AmusementPark()
    : Landmark(CardName::AMUSEMENT_PARK, CardType::MAJOR_ESTABLISHMENT, 16)
{
}

void AmusementPark::OperateEffect(Player* owner,
                                  Player* dice_roller,
                                  std::vector<Player*> players,
                                  Bank* bank)
{
}