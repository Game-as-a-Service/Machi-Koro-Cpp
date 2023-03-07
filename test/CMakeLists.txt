cmake_minimum_required(VERSION 3.5)
project(MachiKoroCPPTest CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    #${CMAKE_CURRENT_SOURCE_DIR}/../models/machikoro_game.cpp
    test_main.cc
    machikoro_game_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../controllers/startGame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../models/game_repository.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../models/machikoro_game.cpp

)

# ##############################################################################
# If you include the drogon source code locally in your project, use this method
# to add drogon 
# target_link_libraries(${PROJECT_NAME}_test PRIVATE drogon)
#
# and comment out the following lines
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

ParseAndAddDrogonTests(${PROJECT_NAME})
