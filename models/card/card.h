#ifndef CARD_H
#define CARD_H

#include <string>
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
    Card() = delete;
    Card(const CardName& name, int price, const CardType& type);
    ~Card() = default;
    
    // TODO: Resolve this dependency relationship.
    virtual void OperateEffect(Player* owner,
        std::vector<Player*> players,
        Bank* bank) = 0;

    CardName get_name() const { return name_; }

    CardType get_card_type() const { return card_type_; }
    
    int get_price() const { return price_; }

private:
    int price_ = 0;
    CardName name_;
    CardType card_type_;
};

#endif