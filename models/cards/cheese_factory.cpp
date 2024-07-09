#include "cheese_factory.h"

#include "models/bank.h"
#include "models/player.h"

CheeseFactory::CheeseFactory()
    : Building(CardName::CHEESE_FACTORY,
               CardType::FACTORY_OR_MARKET,
               5,
               IndustryType::SECONDARY_INDUSTRY,
               { 7 })
{
}

void CheeseFactory::doOperateEffect(Player* owner,
                                  Player* dice_roller,
                                  std::vector<Player*> players,
                                  Bank* bank)
{
}