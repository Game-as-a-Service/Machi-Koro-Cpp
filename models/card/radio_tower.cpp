#include "radio_tower.h"

RadioTower::RadioTower() : 
    Landmark(CardName::RADIO_TOWER, 22, CardType::MAJOR_ESTABLISHMENT)
{
}

void RadioTower::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}