#ifndef UTILS_UTIL_H
#define UTILS_UTIL_H

#include <string>

class Util {
public:
    virtual ~Util() = default;

    virtual std::string generateUUID() const = 0;
};

#endif  // UTILS_UTIL_H