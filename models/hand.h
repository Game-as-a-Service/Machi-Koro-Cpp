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
    
    void AddCard(std::unique_ptr<Card> card) { cards_.push_back(card); }

    void AddLandmark(std::unique_ptr<Card> card) { landmarks_.push_back(card); }

    // TODO(smart pointer): implement this function.
    std::vector<Card*> get_cards() const;

    // TODO(smart pointer): implement this function.
    std::vector<Card*> get_landmarks() const;

private:
    std::vector<std::unique_ptr<Card>> cards_;
    std::vector<std::unique_ptr<Card>> landmarks_;
};

#endif