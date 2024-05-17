#include "card.h"

Card::Card(CardName name, CardType type, int price)
    : card_name_(name)
    , card_type_(type)
    , price_(price)
{
}