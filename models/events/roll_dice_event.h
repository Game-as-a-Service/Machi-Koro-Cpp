#ifndef ROLL_DICE_EVENT_H
#define ROLL_DICE_EVENT_H

#include "domain_event.h"

class RollDiceEvent : public DomainEvent {
public:
    RollDiceEvent(int pt1, int pt2, bool res)
        : point_1_(pt1)
        , point_2_(pt2)
        , is_roll_success_(res)
    {}

    void set_can_reroll(bool res) {
        can_reroll_ = res;
    }

    bool get_can_reroll() const { return can_reroll_; }

    void set_can_roll_next(bool res) {
        can_roll_next_ = res;
    }

    bool get_can_roll_next() const { return can_roll_next_; }

private:
    int point_1_ = 0;
    int point_2_ = 0;
    bool is_roll_success_ = true;
    bool can_reroll_ = false;
    bool can_roll_next_ = false;
};

#endif