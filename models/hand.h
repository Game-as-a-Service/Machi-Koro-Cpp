#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>

#include "./card/card.h"

class Hand {
public:
    Hand();
    ~Hand();
    
    void AddCard(const std::shared_ptr<Card>& card) { cards_.push_back(card); }

    void AddLandmark(const std::shared_ptr<Card>& card) { landmarks_.push_back(card); }

    std::vector<std::shared_ptr<Card>> get_cards() const { return cards_; }

    std::vector<std::shared_ptr<Card>> get_landmarks() const { return landmarks_; }

private:
    std::vector<std::shared_ptr<Card>> cards_;
    std::vector<std::shared_ptr<Card>> landmarks_;
};

#endif