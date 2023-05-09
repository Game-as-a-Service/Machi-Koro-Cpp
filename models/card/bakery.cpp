#include "bakery.h"

Bakery::Bakery() : 
    Building("Bakery", 1, CardType::CROP, {2,3}, IndustryType::SECONDARY_INDUSTRY)
{
}