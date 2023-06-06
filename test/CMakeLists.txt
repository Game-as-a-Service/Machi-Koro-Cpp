cmake_minimum_required(VERSION 3.5)
project(MachiKoroCPPTest CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    machikoro_game_test.cpp
    test_main.cc
)

# ##############################################################################
# If you include the drogon source code locally in your project, use this method
# to add drogon 
# target_link_libraries(${PROJECT_NAME}_test PRIVATE drogon)
#
# and comment out the following lines
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${PROJECT_NAME}
                PRIVATE
               ${MachiKoroCPP_SRC_DIR}
               ${MachiKoroCPP_CTL_SRC}
               ${MachiKoroCPP_FILTER_SRC}
               ${MachiKoroCPP_PLUGIN_SRC}
               ${MachiKoroCPP_USECASES_SRC}
               ${MachiKoroCPP_MODEL_SRC}
               ${MachiKoroCPP_CARDS_SRC})

ParseAndAddDrogonTests(${PROJECT_NAME})
