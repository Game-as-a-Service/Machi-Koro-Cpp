#ifndef UTILS_UTIL_H
#define UTILS_UTIL_H

#include <map>
#include <memory>
#include <string>
#include <functional>

#include "utils/util_base.h"

class Util : public UtilBase {
public:
    // Non-copyable.
    Util(const Util&) = delete;
    Util& operator=(const Util&) = delete;

    static std::shared_ptr<Util> self();

    std::string generateUUID() const override;

    BuildingPtrs generateBuildings(const CardName& name, int num) override;

    std::string getStringFromCardName(const CardName& name) override;

private:
    Util();

private:
    // All the building generator functions.
    std::map<CardName, std::function<BuildingPtrs(int)>> building_generators_;
};

#endif  // UTILS_UTIL_H