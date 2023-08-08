#include "hand.h"

Hand::Hand()
{
}

Hand::~Hand()
{
    for (auto& c : cards_) c = nullptr;
    cards_.clear();
    for (auto& l : landmarks_) l = nullptr;
    landmarks_.clear();
}

std::vector<Card*> Hand::get_cards() const
{
    std::vector<Card*> res;
    for (const auto& card : cards_)
        res.push_back(card.get());
    return res;
}

std::vector<Card*> Hand::get_landmarks() const
{
    std::vector<Card*> res;
    for (const auto& card: landmarks_)
        res.push_back(card.get());
    return res;
}