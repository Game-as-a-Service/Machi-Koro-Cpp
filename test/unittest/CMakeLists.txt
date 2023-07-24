include(CTest)
set(TEST_BINARY ${PROJECT_NAME}_game_unittest)

file(GLOB model_src ../../models/*.cpp)
file(GLOB card_src ../../models/card/*.cpp)

add_executable(${TEST_BINARY}
    game_unittest.cpp
    ${model_src}
    ${card_src}
)

target_link_libraries(${TEST_BINARY} gtest gtest_main pthread)
add_test(game_unittest test/game_unittest/game_unittest.cpp)