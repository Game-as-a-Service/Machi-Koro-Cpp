#ifndef CARD_H
#define CARD_H

#include <string>

enum class IndustryType {
    RESTAURANT,
    SECONDARY_INDUSTRY,
    PRIMARY_INDUSTRY,
    IMPORTANT_BUILDING
};

enum class CardType {
    CROP,
    NATURE_RESOURCES,
    ANIMAL_HUSBANDRY,
    SHOP,
    RESTAURANT,
    FACTORY_OR_MARKET,
    MAJOR_ESTABLISHMENT
};

class Card {
public:
    Card();
    Card(const std::string& name, int price, const CardType& type);
    ~Card();
    
    virtual void OperateEffect() = 0;

    void set_name(const std::string& name) { name_ = name; }
    std::string get_name() const { return name_; }

    void set_card_type(const CardType& type) { card_type_ = type; }
    CardType get_card_type() const { return card_type_; }
    
    int get_price() const { return price_; }

private:
    int price_;
    std::string name_;
    CardType card_type_;
};

#endif