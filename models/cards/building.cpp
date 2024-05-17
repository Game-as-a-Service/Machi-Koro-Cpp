#include "building.h"

#include <vector>

Building::Building(CardName name,
                   CardType type,
                   int price,
                   IndustryType ind,
                   std::vector<int>&& points)
    : Card(name, type, price)
    , ind_type_(ind)
    , points_(points)
{
}