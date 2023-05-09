#ifndef BUILDING_H
#define BUILDING_H

#include <vector>

#include "card.h"

class Building : public Card {
public:
    Building();
    Building(const std::string& name, int price, const CardType& card_type, 
        std::vector<int> points, const IndustryType& ind_type);
    ~Building();

    virtual void OperateEffect() = 0;

    std::vector<int> get_points() const { return points_; }

private:
    std::vector<int> points_;
    IndustryType industry_type_;
};

#endif