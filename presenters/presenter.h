#ifndef PRESENTERS_PRESENTER_H
#define PRESENTERS_PRESENTER_H

#include "models/events/event.h"

class Presenter {
public:
    virtual ~Presenter() = default;

    /**
     * @brief Receive the datas those want to pass back to front-end.
     */
    virtual void present(Event* event) = 0;
};

#endif  // PRESENTERS_PRESENTER_H