#include "furniture_factory.h"

FurnitureFactory::FurnitureFactory() : 
    Building(CardName::FURNITURE_FACTORY, 3, CardType::FACTORY_OR_MARKET, {8}, IndustryType::SECONDARY_INDUSTRY)
{
}