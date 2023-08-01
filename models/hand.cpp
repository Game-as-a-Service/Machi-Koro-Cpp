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