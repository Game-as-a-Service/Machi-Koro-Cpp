#include "amusement_park.h"

#include "models/bank.h"
#include "models/player.h"

AmusementPark::AmusementPark()
    : Landmark(CardName::AMUSEMENT_PARK, CardType::MAJOR_ESTABLISHMENT, 16)
{
}

void AmusementPark::operateEffect(Player* owner,
                       Player* dice_roller,
                       int point,
                       std::vector<Player*> players,
                       Bank* bank,
                       IndustryType curr_industry_type)
{
}