#include "cheese_factory.h"

CheeseFactory::CheeseFactory() : 
    Building("Cheese Factory", 5, CardType::FACTORY_OR_MARKET, {7}, IndustryType::SECONDARY_INDUSTRY)
{
}