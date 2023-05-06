#ifndef HAND_H
#define HAND_H

#include <vector>

#include "./card/card.h"

class Hand {
public:
    Hand();
    ~Hand();
    
    void AddCard(const Card& card) { cards_.push_back(card); }

    void set_cards(const std::vector<Card>& cards) { cards_ = cards; }
    std::vector<Card> get_cards() const { return cards_; }

private:
    std::vector<Card> cards_;
};

#endif