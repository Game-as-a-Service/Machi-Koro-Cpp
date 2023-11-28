#include "radio_tower.h"

RadioTower::RadioTower() :
    Landmark(CardName::RADIO_TOWER, 22, CardType::MAJOR_ESTABLISHMENT)
{
}

void RadioTower::OperateEffect(Player* owner,
    Player* dice_roller,
    std::vector<Player*> players,
    Bank* bank)
{

}