cmake_minimum_required(VERSION 3.20.0)

# Optional to set compiler path.
# It's must been seted before "Language".
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-12")

project(MachiKoroCPP
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Target
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/machikoro_game.cpp
    src/player.cpp
    src/bank.cpp
    src/architecture_market.cpp
    src/card.cpp
    src/hand.cpp
    src/landmark.cpp
    src/building.cpp
    src/initial_building.cpp
    src/general_building.cpp
    src/important_building.cpp
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)