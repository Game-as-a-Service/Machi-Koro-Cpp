#include "radio_tower.h"

#include "models/bank.h"
#include "models/player.h"

RadioTower::RadioTower()
    : Landmark(CardName::RADIO_TOWER, CardType::MAJOR_ESTABLISHMENT, 22)
{
}

void RadioTower::operateEffect(Player* owner,
                       Player* dice_roller,
                       int point,
                       std::vector<Player*> players,
                       Bank* bank,
                       IndustryType curr_industry_type)
{
}