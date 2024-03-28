#!/bin/bash

ROOT_DIR="$(cd "$(dirname "$BASH_SOURCE")" && pwd)" || {
    echo "Error getting script directory" >&2
    exit 1
}
OUTPUT_FILE="$ROOT_DIR/cmake/sources.cmake"

# Check folder whether if exist or not.

if [ ! -d "$ROOT_DIR/cmake" ]; then
    mkdir -p "$ROOT_DIR/cmake"
fi

# controllers/.

echo "set(CONTROLLER_HEADERS" > $OUTPUT_FILE
find $ROOT_DIR/controllers -type f \( -name "*.h" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

echo "set(CONTROLLER_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/controllers -type f \( -name "*.cc" -o -name "*.cpp" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

# presenters/.

echo "set(PRESENTER_HEADERS" >> $OUTPUT_FILE
find $ROOT_DIR/presenters -type f \( -name "*.h" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

echo "set(PRESENTER_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/presenters -type f \( -name "*.cc" -o -name "*.cpp" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

# loggers/.

echo "set(LOGGER_HEADERS" >> $OUTPUT_FILE
find $ROOT_DIR/loggers -type f \( -name "*.h" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

echo "set(LOGGER_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/loggers -type f \( -name "*.cc" -o -name "*.cpp" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

# repos/.

echo "set(REPO_HEADERS" >> $OUTPUT_FILE
find $ROOT_DIR/repos -type f \( -name "*.h" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

echo "set(REPO_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/repos -type f \( -name "*.cc" -o -name "*.cpp" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

# utils/.

echo "set(UTIL_HEADERS" >> $OUTPUT_FILE
find $ROOT_DIR/utils -type f \( -name "*.h" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

echo "set(UTIL_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/utils -type f \( -name "*.cc" -o -name "*.cpp" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

# usecases/.

echo "set(USECASE_HEADERS" >> $OUTPUT_FILE
find $ROOT_DIR/usecases -type f \( -name "*.h" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

echo "set(USECASE_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/usecases -type f \( -name "*.cc" -o -name "*.cpp" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

# models/.

echo "set(MODEL_HEADERS" >> $OUTPUT_FILE
find $ROOT_DIR/models -type f \( -name "*.h" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

echo "set(MODEL_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/models -type f \( -name "*.cc" -o -name "*.cpp" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

# tests/e2e_test/.

echo "set(E2E_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/tests/e2e_test -type f \( -name "*.cc" -o -name "*.cpp" -o -name "*.h" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE

# tests/unittest/.

echo "set(UNIT_SOURCES" >> $OUTPUT_FILE
find $ROOT_DIR/tests/unittest -type f \( -name "*.cc" -o -name "*.cpp" \) | sed "s|$ROOT_DIR|\\\${CMAKE_SOURCE_DIR}|g" | sed 's/^/    /' >> $OUTPUT_FILE
echo ")" >> $OUTPUT_FILE