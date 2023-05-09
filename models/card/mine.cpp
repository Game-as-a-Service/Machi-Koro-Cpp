#include "mine.h"

Mine::Mine() : 
    Building("Mine", 6, CardType::NATURE_RESOURCES, {9}, IndustryType::PRIMARY_INDUSTRY)
{
}