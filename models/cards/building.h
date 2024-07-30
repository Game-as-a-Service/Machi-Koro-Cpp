#ifndef MODELS_CARDS_BUILDING_H
#define MODELS_CARDS_BUILDING_H

#include <vector>
#include <memory>

#include "card.h"

enum class IndustryType {
    RESTAURANT,
    SECONDARY_INDUSTRY,
    PRIMARY_INDUSTRY,
    IMPORTANT_BUILDING
};

class Building;
using BuildingPtr = std::unique_ptr<Building>;
using BuildingPtrs = std::vector<BuildingPtr>;

template<typename T>
BuildingPtrs generateBuildingsTemp(int count)
{
    std::vector<BuildingPtr> res;
    for (int i = 0; i < count; ++i) res.push_back(std::make_unique<T>());
    return res;
}

class Building : public Card {
public:
    Building(const CardName& name,
             const CardType& type,
             int price,
             const IndustryType& ind,
             std::vector<int>&& points);

    ~Building() = default;

    /**
     * @brief Operate the effect of the building card
     * @param owner The player who owns the building card
     * @param dice_roller The player who rolls the dice in this round
     * @param point The point of the dice
     * @param players All the players in the game
     * @note This method checks whether the effect should be operated according
     *       to the industry type, owner, point, and dice_roller.
     *       E.g. For SECONDARY_INDUSTRY, the owner and the dice_roller should
     *       be the same person.
     */
    virtual void operateEffect(Player* owner,
                       Player* dice_roller,
                       int point,
                       std::vector<Player*> players,
                       Bank* bank,
                       IndustryType curr_industry_type) override;

    IndustryType industryType() const { return ind_type_; }

    std::vector<int> points() const { return points_; }

protected:
    /**
     * @brief The actual effect of the building card
     * @note This method will not perform any check.
     */
    virtual void doOperateEffect(Player* owner, Player* dice_roller,
                         std::vector<Player*> players, Bank* bank) = 0;

private:
    /**
     * Verify if the effect should be operated based on the IndustryType
     * and the point of the dice.
     * The industry type of this building card should be the same as the
     * current industry type.
     * @param curr_industry_type The current industry type that should do operation
     */
    bool verify(Player* owner, Player* dice_roller, int point, IndustryType curr_industry_type);

    IndustryType ind_type_;

    std::vector<int> points_;
};

#endif  // MODELS_CARDS_BUILDING_H