#ifndef UTILS_UTIL_H
#define UTILS_UTIL_H

#include <memory>
#include <string>

#include "utils/util_base.h"

class Util : public UtilBase {
public:
    Util(const Util&) = delete;

    Util& operator=(const Util&) = delete;

    static std::shared_ptr<Util> self();

    std::string generateUUID() const override;

private:
    Util() = default;
};

#endif  // UTILS_UTIL_H