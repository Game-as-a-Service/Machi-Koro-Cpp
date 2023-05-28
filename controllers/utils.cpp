#include "utils.h"

namespace controllers {
namespace utils {

std::vector<std::string> JsonValueToVectorOfString(const Json::Value& json_value) 
{
    std::vector<std::string> values;
    for (const auto& tmp : json_value) 
    {
        assert(tmp.isString() && "JsonValueToVectorOfString: json_value is not string");
        values.push_back(tmp.asString());
    }
    return values;
}

}  // namespace utils
}  // namespace controllers