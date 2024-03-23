#ifndef UTILS_UTIL_IMPL_H
#define UTILS_UTIL_IMPL_H

#include <memory>
#include <string>

#include "utils/util.h"

class UtilImpl : public Util {
public:
    UtilImpl(const UtilImpl&) = delete;

    UtilImpl& operator=(const UtilImpl&) = delete;

    static std::shared_ptr<UtilImpl> self();

    std::string generateUUID() const override;

private:
    UtilImpl() = default;
};

#endif  // UTILS_UTIL_IMPL_H