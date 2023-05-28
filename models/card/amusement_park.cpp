#include "amusement_park.h"

AmusementPark::AmusementPark() : 
    Landmark(CardName::AMUSEMENT_PARK, 16, CardType::MAJOR_ESTABLISHMENT)
{
}

void AmusementPark::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}