#include "utils/util_impl.h"

#include "drogon/utils/Utilities.h"

std::shared_ptr<UtilImpl> UtilImpl::self()
{
    static std::shared_ptr<UtilImpl> util(new UtilImpl);
    return util;
}

std::string UtilImpl::generateUUID() const
{
    return drogon::utils::getUuid();
}