#include "building.h"

#include <vector>

Building::Building(const CardName& name,
                   const CardType& type,
                   int price,
                   const IndustryType& ind,
                   std::vector<int>&& points)
    : Card(name, type, price)
    , ind_type_(ind)
    , points_(points)
{
}