#ifndef BUILDING_H
#define BUILDING_H

#include "card.h"

class Building : public Card {
public:
    Building();
    Building(const std::string& name, int price, const CardType& card_type, 
        int points, const IndustryType& ind_type);
    ~Building();

    virtual void OperateEffect() = 0;

    void set_points(int point) { points_ = point; }
    int get_points() const { return points_; }

private:
    int points_ = 1;
    IndustryType industry_type_;
};

#endif