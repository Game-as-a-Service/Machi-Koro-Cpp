#ifndef UTILS_UTIL_BASE_H
#define UTILS_UTIL_BASE_H

#include <string>

#include "models/cards/building.h"

class UtilBase {
public:
    virtual ~UtilBase() = default;

    virtual std::string generateUUID() const = 0;

    virtual BuildingPtrs generateBuildings(const CardName& name, int num) = 0;

    virtual std::string getStringFromCardName(const CardName& name) = 0;
};

#endif  // UTILS_UTIL_BASE_H