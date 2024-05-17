#ifndef MODELS_CARDS_CARD_H
#define MODELS_CARDS_CARD_H

#include <vector>
#include <memory>

enum class CardType {
    CROP,
    NATURE_RESOURCES,
    ANIMAL_HUSBANDRY,
    SHOP,
    RESTAURANT,
    FACTORY_OR_MARKET,
    MAJOR_ESTABLISHMENT
};

enum class CardName {
    APPLE_ORCHARD,
    BAKERY,
    BUSINESS_CENTER,
    CAFE,
    CHEESE_FACTORY,
    CONVENIENCE_STORE,
    FAMILY_RESTAURANT,
    FOREST,
    FRUIT_AND_VEGETABLE_MARKET,
    FURNITURE_FACTORY,
    MINE,
    RANCH,
    STADIUM,
    TV_STATION,
    WHEAT_FIELD,
    TRAIN_STATION,
    SHOPPING_MALL,
    AMUSEMENT_PARK,
    RADIO_TOWER
};

class Bank;
class Player;

class Card {
public:
    Card(CardName name, CardType type, int price);

    ~Card() = default;

    // TODO: Resolve this dependency relationship.
    virtual void OperateEffect(Player* owner,
                               Player* dice_roller,
                               std::vector<Player*> others,
                               std::shared_ptr<Bank> bank) = 0;

    CardName card_name() const { return card_name_; }

    CardType card_type() const { return card_type_; }

    int price() const { return price_; }

private:
    CardName card_name_;

    CardType card_type_;

    int price_ = 0;
};

#endif  // MODELS_CARDS_CARD_H