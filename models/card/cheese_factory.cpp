#include "cheese_factory.h"

CheeseFactory::CheeseFactory() : 
    Building(CardName::CHEESE_FACTORY, 5, CardType::FACTORY_OR_MARKET, {7}, IndustryType::SECONDARY_INDUSTRY)
{
}