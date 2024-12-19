cmake_minimum_required(VERSION 3.00)
project(roller CXX)
set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0  # You can change the version as needed
)
FetchContent_MakeAvailable(gtest)

set(LIB1_SOURCES src/libs-src/parser.cpp)
set(LIB2_SOURCES src/libs-src/error.cpp)
set(LIB3_SOURCES src/libs-src/hashtable.cpp)
set(LIB4_SOURCES src/libs-src/lexer.cpp)

add_library(Parser STATIC ${LIB1_SOURCES})
add_library(Error STATIC ${LIB2_SOURCES})
add_library(HashTable STATIC ${LIB3_SOURCES})
add_library(Lexer STATIC ${LIB4_SOURCES})

target_include_directories(Parser PUBLIC src/libs/parser.hh)
target_include_directories(Error PUBLIC src/libs/error.hh)
target_include_directories(HashTable PUBLIC src/libs/hashtable.hh)
target_include_directories(Lexer PUBLIC src/libs/lexer.hh)

add_executable(roller_tests test/test.cpp)
add_executable(roller src/main.cpp)

target_link_libraries(roller PRIVATE Parser Error HashTable Lexer)
target_link_libraries(roller_tests PRIVATE gtest gtest_main HashTable Lexer)

enable_testing()
add_test(NAME Roller_Test COMMAND roller_tests)
