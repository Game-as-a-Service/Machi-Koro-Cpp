cmake_minimum_required(VERSION 3.16)
project(MachiKoroCPP 
    VERSION 0.0.1
    LANGUAGES CXX
)

# ---------------------------------------------------------------------------------------
# Set project options.
# ---------------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif ()

message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}. \n")

# ---------------------------------------------------------------------------------------
# Package dependency.
# ---------------------------------------------------------------------------------------

find_package(Drogon CONFIG REQUIRED)
find_package(GTest)

if (NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         v1.14.0
    )
    FetchContent_MakeAvailable(googletest)
endif (NOT GTest_FOUND)

# ---------------------------------------------------------------------------------------
# Headers & Sources.
# ---------------------------------------------------------------------------------------

include(cmake/sources.cmake)

# Model Library

add_library(Model SHARED "")
target_sources(Model
    PRIVATE
    ${MODEL_SOURCES}
    ${MODEL_HEADERS}
)
target_include_directories(Model
    PRIVATE
    ${CMAKE_SOURCE_DIR}/models
    ${CMAKE_SOURCE_DIR}/models/card
    ${CMAKE_SOURCE_DIR}/models/events
)

# Controller2Usecase Library

add_library(Controller2Usecase SHARED "")
target_sources(Controller2Usecase
    PRIVATE
    ${CONTROLLER_SOURCES}
    ${CONTROLLER_HEADERS}
    ${LOGGER_SOURCES}
    ${LOGGER_HEADERS}
    ${REPO_SOURCES}
    ${REPO_HEADERS}
    ${UTIL_SOURCES}
    ${UTIL_HEADERS}
    ${PRESENTER_SOURCES}
    ${PRESENTER_HEADERS}
    ${USECASE_SOURCES}
    ${USECASE_HEADERS}
)
target_include_directories(Controller2Usecase
    PRIVATE
    ${CMAKE_SOURCE_DIR}/controllers
    ${CMAKE_SOURCE_DIR}/loggers
    ${CMAKE_SOURCE_DIR}/repos
    ${CMAKE_SOURCE_DIR}/utils
    ${CMAKE_SOURCE_DIR}/presenters
    ${CMAKE_SOURCE_DIR}/usecases
)
target_link_libraries(Controller2Usecase
    PRIVATE
    Model
    PUBLIC
    Drogon::Drogon
)

# app

add_executable(${PROJECT_NAME}_app main.cpp)
target_link_libraries(${PROJECT_NAME}_app
    PRIVATE
    Controller2Usecase
)

# drogon_create_views(${PROJECT_NAME} 
#     ${CMAKE_CURRENT_SOURCE_DIR}/views
#     ${CMAKE_CURRENT_BINARY_DIR}
# )

# ---------------------------------------------------------------------------------------
# Clang-format.
# ---------------------------------------------------------------------------------------

include(cmake/clang-format.cmake)

# ---------------------------------------------------------------------------------------
# E2E Test & Unit Test.
# ---------------------------------------------------------------------------------------

enable_testing()

# E2E Test

add_executable(${PROJECT_NAME}_e2e
    ${E2E_SOURCES}
)
target_include_directories(${PROJECT_NAME}_e2e
    PRIVATE
    ${CMAKE_SOURCE_DIR}/usecases
    ${CMAKE_SOURCE_DIR}/models
)
target_link_libraries(${PROJECT_NAME}_e2e
    PRIVATE
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
    pthread
    Model
    Controller2Usecase
)

# Unit Test

add_executable(${PROJECT_NAME}_unit
    ${UNIT_SOURCES}
)
target_link_libraries(${PROJECT_NAME}_unit
    PRIVATE
    GTest::gtest
    GTest::gtest_main
    pthread
    Model
    Controller2Usecase
)

# Discover

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_e2e)
gtest_discover_tests(${PROJECT_NAME}_unit)