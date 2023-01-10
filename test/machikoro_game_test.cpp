#include <drogon/drogon_test.h>
#include <drogon/drogon.h>

#include "../models/machikoro_game.h"

DROGON_TEST(GameTest)
{
    // Add your tests here
    MachiKoroGame game;
    CHECK(game.DummyTest() == true);
}