#include <drogon/drogon.h>

#include <iostream>
#include <string>
#include <vector>

#include "models/machikoro_game.h"

int main() {
    /*
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 8080);

    //Load config file
    //drogon::app().loadConfigFile("../config.json");

    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();

    */
    std::vector<std::string> names = {"Alice", "Bob", "Cindy", "David"};
    MachiKoroGame game(names);
    std::cout << "Game ID: " << game.get_game_id() << std::endl;
    std::cout << "players: " << std::endl;
    for (const auto& player: game.get_players()) {
        std::cout << player->get_name() << std::endl;
    }
    return 0;
}
