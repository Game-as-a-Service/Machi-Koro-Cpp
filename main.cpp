#include "drogon/drogon.h"

// TODO(#39): Fix 404 error without including controllers
#include "controllers/clear_game_controller.h"
#include "controllers/create_game_controller.h"
#include "controllers/init_game_controller.h"

int main()
{
    const std::string strConfig =
        "{\"listeners\":[{\"address\":\"127.0.0.1\",\"port\":8080}],\"app\":{\"log\":{\"use_"
        "spdlog\":true,\"log_level\":\"TRACE\"}},\"plugins\":[{\"name\":\"drogon::plugin::"
        "AccessLogger\",\"config\":{\"use_spdlog\":true}}]}";
    Json::Value jsonConfig;
    Json::Reader reader;
    reader.parse(strConfig, jsonConfig);

    drogon::app().loadConfigJson(jsonConfig);
    drogon::app().run();

    return 0;
}
