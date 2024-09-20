#ifndef MODELS_CARDS_LANDMARK_H
#define MODELS_CARDS_LANDMARK_H

#include <memory>
#include <vector>

#include "card.h"

class Landmark;
using LandmarkPtr = std::unique_ptr<Landmark>;
using LandmarkPtrs = std::vector<LandmarkPtr>;

class Landmark : public Card {
public:
    Landmark(const CardName& name, const CardType& type, int price);

    ~Landmark() = default;

    virtual void operateEffect(Player* owner,
                       Player* dice_roller,
                       int point,
                       std::vector<Player*> players,
                       Bank* bank,
                       IndustryType curr_industry_type) = 0;

    void activate() { is_activated_ = true; }

    bool is_activate() const { return is_activated_; }

private:
    // False: 背面, True: 正面。
    bool is_activated_ = false;
};

#endif  // MODELS_CARDS_LANDMARK_H