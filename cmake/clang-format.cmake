if (NOT ${PROJECT_NAME}_CLANG_FORMAT)
    find_program(${PROJECT_NAME}_CLANG_FORMAT clang-format)
endif ()

if (${PROJECT_NAME}_CLANG_FORMAT)
    add_custom_target(CLANG_FORMAT
        COMMAND ${${PROJECT_NAME}_CLANG_FORMAT}
            -i  ${CMAKE_SOURCE_DIR}/main.cpp
                ${CONTROLLER_HEADERS}
                ${CONTROLLER_SOURCES}
                ${LOGGER_HEADERS}
                ${LOGGER_SOURCES}
                ${REPO_HEADERS}
                ${REPO_SOURCES}
                ${UTIL_HEADERS}
                ${UTIL_SOURCES}
                ${PRESENTER_HEADERS}
                ${PRESENTER_SOURCES}
                ${USECASE_HEADERS}
                ${USECASE_SOURCES}
                ${MODEL_HEADERS}
                ${MODEL_SOURCES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
    message(STATUS "Format the project using the `CLANG_FORMAT` target \
        (i.e: cmake --build build --target CLANG_FORMAT).")
endif ()