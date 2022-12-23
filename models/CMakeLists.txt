file(GLOB models_src src/*.cpp)
list(REMOVE_ITEM models_src "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_library(models ${models_src})
target_include_directories(models PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
