cmake_minimum_required(VERSION 3.28)
project(fluidsim)

find_package(raylib QUIET)

if(NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 6.0
        GIT_PROGRESS TRUE
    )
    FetchContent_MakeAvailable(raylib)
endif()

add_executable(fluidsim)
target_sources(fluidsim
	PRIVATE
	src/main.cpp
)

target_link_libraries(fluidsim PRIVATE raylib)
