cmake_minimum_required(VERSION 3.28)
project(fluidsim LANGUAGES CXX)
enable_testing()

find_package(raylib QUIET)

if(NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 6.0
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(raylib)
endif()

find_package(Catch2 QUIET)

if(NOT Catch2_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)
endif()

add_executable(fluidsim)
target_compile_features(fluidsim PRIVATE cxx_std_23)
target_sources(fluidsim PRIVATE src/main.cpp)
target_include_directories(fluidsim PRIVATE include)
target_link_libraries(fluidsim PRIVATE raylib)

add_executable(tests)
target_compile_features(tests PRIVATE cxx_std_23)
target_sources(tests PRIVATE tests/vec2_tests.cpp)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(tests)
