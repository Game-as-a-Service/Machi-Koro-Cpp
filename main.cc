#include <drogon/drogon.h>
#include "models/machikoro_game.h"

int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 8080);

    //Load config file
    //drogon::app().loadConfigFile("../config.json");

    MachiKoroGame game;
    game.GameStart();

    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();

    return 0;
}
