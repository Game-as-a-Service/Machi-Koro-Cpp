#include "drogon/drogon.h"

// TODO(#39): Fix 404 error without including controllers
#include "controllers/clear_game_controller.h"
#include "controllers/create_game_controller.h"
#include "controllers/init_game_controller.h"

int main()
{
    // Set HTTP listener address and port
    drogon::app().addListener("127.0.0.1", 8080);

    // Load config file
    // drogon::app().loadConfigFile("../config.json");

    // Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();

    return 0;
}
