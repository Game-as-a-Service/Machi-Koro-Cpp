#include "card.h"

Card::Card(const std::string& name, int price, const CardType& type) :
      name_(name)
    , price_(price)
    , card_type_(type)
{
}