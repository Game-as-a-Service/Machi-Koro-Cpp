#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>

#include "card/card.h"

class Card;

class Hand {
public:
    Hand();
    ~Hand();

    void AddBuilding(std::unique_ptr<Card> card) 
    { buildings_.push_back(std::move(card)); }

    void AddLandmark(std::unique_ptr<Card> card) 
    { landmarks_.push_back(std::move(card)); }

    std::vector<Card*> get_buildings() const;

    std::vector<Card*> get_landmarks() const;

private:
    std::vector<std::unique_ptr<Card>> buildings_;
    std::vector<std::unique_ptr<Card>> landmarks_;
};

#endif