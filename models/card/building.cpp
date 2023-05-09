#include "building.h"

Building::Building(const std::string& name, int price, const CardType& card_type, 
    const std::vector<int>& points, const IndustryType& ind_type) : 
      Card(name, price, card_type)
    , points_(points)
    , industry_type_(ind_type)
{
};
