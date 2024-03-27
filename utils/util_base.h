#ifndef UTILS_UTIL_BASE_H
#define UTILS_UTIL_BASE_H

#include <string>

class UtilBase {
public:
    virtual ~UtilBase() = default;

    virtual std::string generateUUID() const = 0;
};

#endif  // UTILS_UTIL_BASE_H