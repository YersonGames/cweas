cmake_minimum_required(VERSION 3.23)

project(test
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        6.0
)
FetchContent_MakeAvailable(raylib)

add_executable(main
    gametest/src/Bullet.cpp)

target_sources(main
    PRIVATE
        gametest/game.cpp
        gametest/src/Player.cpp
        gametest/src/Enemy.cpp
        gametest/src/utils.cpp
)

target_include_directories(main PRIVATE gametest/src)

target_link_libraries(main PRIVATE raylib)