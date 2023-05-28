#include <cassert>
#include <json/json.h>
#include <string>

namespace controllers {
namespace utils {

const std::string game_id = "Game ID";
const std::string player_names = "Player Names";

std::vector<std::string> JsonValueToVectorOfString(const Json::Value& json_value);

}  // namespace utils
}  // namespace controllers