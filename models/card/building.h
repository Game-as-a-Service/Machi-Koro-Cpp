#ifndef BUILDING_H
#define BUILDING_H

#include <vector>

#include "card.h"

enum class IndustryType {
    RESTAURANT,
    SECONDARY_INDUSTRY,
    PRIMARY_INDUSTRY,
    IMPORTANT_BUILDING
};

class Building : public Card {
public:
    Building() = delete;
    Building(const CardName& name, int price, const CardType& card_type, 
        const std::vector<int>& points, const IndustryType& ind_type);
    ~Building() = default;

    virtual void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) = 0;

    std::vector<int> get_points() const { return points_; }
    IndustryType get_industry_type() const { return industry_type_; }

private:
    std::vector<int> points_;
    IndustryType industry_type_;
};

#endif