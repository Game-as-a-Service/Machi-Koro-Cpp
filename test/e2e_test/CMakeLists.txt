include(CTest)
cmake_minimum_required(VERSION 3.5)
project(MachiKoroCPPTest CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
               test_main.cc
               game_setup_e2etest.cpp )

# ##############################################################################
# If you include the drogon source code locally in your project, use this method
# to add drogon
# target_link_libraries(${PROJECT_NAME}_test PRIVATE drogon)
#
# and comment out the following lines
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon gtest gtest_main pthread)

target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(../../controllers CTL_SRC_TEST)
aux_source_directory(../../filters FILTER_SRC_TEST)
aux_source_directory(../../plugins PLUGIN_SRC_TEST)
aux_source_directory(../../usecases USECASES_SRC_TEST)
aux_source_directory(../../models MODEL_SRC_TEST)
aux_source_directory(../../models/card CARDS_SRC_TEST)
aux_source_directory(../../models/events EVENTS_SRC_TEST)

target_sources(${PROJECT_NAME}
               PRIVATE
               ${CTL_SRC_TEST}
               ${FILTER_SRC_TEST}
               ${PLUGIN_SRC_TEST}
               ${USECASES_SRC_TEST}
               ${MODEL_SRC_TEST}
               ${CARDS_SRC_TEST}
               ${EVENTS_SRC_TEST})

add_test(game_setup_e2etest test/e2e_test/machikoro_game_test.cpp)