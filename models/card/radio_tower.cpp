#include "radio_tower.h"

RadioTower::RadioTower() : 
    Landmark(CardName::RADIO_TOWER, 22, CardType::MAJOR_ESTABLISHMENT)
{
}

void RadioTower::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}