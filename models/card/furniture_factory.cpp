#include "furniture_factory.h"

FurnitureFactory::FurnitureFactory() : 
    Building(CardName::FURNITURE_FACTORY, 3, CardType::FACTORY_OR_MARKET, {8}, IndustryType::SECONDARY_INDUSTRY)
{
}

void FurnitureFactory::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}