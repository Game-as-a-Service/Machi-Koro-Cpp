#include "card.h"

Card::Card(const CardName& name, const CardType& type, int price)
    : card_name_(name)
    , card_type_(type)
    , price_(price)
{
}