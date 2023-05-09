#include "furniture_factory.h"

FurnitureFactory::FurnitureFactory() : 
    Building("Furniture Factory", 3, CardType::FACTORY_OR_MARKET, {8}, IndustryType::SECONDARY_INDUSTRY)
{
}