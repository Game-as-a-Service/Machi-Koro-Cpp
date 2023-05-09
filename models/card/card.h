#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

#include "../bank.h"
#include "../player.h"

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
    Card() = delete;
    Card(const std::string& name, int price, const CardType& type);
    ~Card() = default;
    
    virtual void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) = 0;

    std::string get_name() const { return name_; }

    CardType get_card_type() const { return card_type_; }
    
    int get_price() const { return price_; }

private:
    int price_ = 0;
    std::string name_;
    CardType card_type_;
};

#endif