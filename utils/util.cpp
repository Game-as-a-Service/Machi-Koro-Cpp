#include "utils/util.h"

#include "drogon/utils/Utilities.h"

std::shared_ptr<Util> Util::self()
{
    static std::shared_ptr<Util> util(new Util);
    return util;
}

std::string Util::generateUUID() const
{
    return drogon::utils::getUuid();
}