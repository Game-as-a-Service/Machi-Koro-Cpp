#include "building.h"

#include <algorithm>
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

void Building::operateEffect(Player* owner,
                             Player* dice_roller,
                             int point,
                             std::vector<Player*> players,
                             Bank* bank,
                             IndustryType curr_industry_type) {
    bool verify_result = verify(owner, dice_roller, point, curr_industry_type);
    if (verify_result) {
        doOperateEffect(owner, dice_roller, players, bank);
    }
}

bool Building::verify(Player* owner, Player* dice_roller, int point, IndustryType curr_industry_type) {
    if (ind_type_ != curr_industry_type) {
        return false;
    } else if (std::find(points_.begin(), points_.end(), point) == points_.end()) {
        return false;
    }

    if (ind_type_ == IndustryType::SECONDARY_INDUSTRY && owner != dice_roller) {
        return false;
    }
    // TODO: Add more verification rules here

    return true;
}