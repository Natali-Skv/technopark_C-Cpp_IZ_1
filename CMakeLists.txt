cmake_minimum_required(VERSION 3.4)
project(IZ-1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -Werror -Wall -Wextra")

add_library(word_lib STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/project/word_lib/word.c
        )

add_executable(IZ-1
        ${CMAKE_CURRENT_SOURCE_DIR}/project/src/main.c)

target_include_directories(IZ-1
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/project/include
        )

target_include_directories(word_lib
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/project/include
        )

target_link_libraries(IZ-1 word_lib)

enable_testing()
find_package(GTest CONFIG REQUIRED)
add_executable(tests
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
        )

target_include_directories(tests
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/project/include
        ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries(tests GTest::gtest_main word_lib)



