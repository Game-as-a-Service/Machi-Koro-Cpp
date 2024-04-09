#include "furniture_factory.h"

#include "models/bank.h"
#include "models/player.h"

FurnitureFactory::FurnitureFactory()
    : Building(CardName::FURNITURE_FACTORY,
               CardType::FACTORY_OR_MARKET,
               3,
               IndustryType::SECONDARY_INDUSTRY,
               { 8 })
{
}

void FurnitureFactory::OperateEffect(Player* owner,
                                     Player* dice_roller,
                                     std::vector<Player*> players,
                                     Bank* bank)
{
}