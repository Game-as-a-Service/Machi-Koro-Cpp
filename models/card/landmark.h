#ifndef LANDMARK_H
#define LANDMARK_H

#include "card.h"

class Landmark: public Card {
public:
    Landmark() = delete;
    Landmark(const CardName& name, int price, const CardType& type);
    ~Landmark() = default;

    virtual void OperateEffect(std::shared_ptr<Player>& owner,
        std::vector<std::shared_ptr<Player>>& players,
        std::shared_ptr<Bank>& bank) = 0;

    bool IsActivate() const { return is_activated_; };
    void Activate() { is_activated_ = true; }

private:
    // False: 背面, True: 正面。
    bool is_activated_ = false;
};

#endif