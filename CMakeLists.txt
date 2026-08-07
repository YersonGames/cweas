cmake_minimum_required(VERSION 3.23)

project(test
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir FetchContent
include(FetchContent)

# Declarar la dependencia de Raylib desde GitHub
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        6.0 # Puedes especificar una versión fija o 'master'
)
FetchContent_MakeAvailable(raylib)

# Crear el ejecutable
add_executable(main)

target_sources(main
    PRIVATE
        gametest/game.cpp
        gametest/src/Player.cpp
        gametest/src/Enemy.cpp
        gametest/src/utils.cpp
)

target_include_directories(main PRIVATE gametest/src)

# Vincular Raylib con tu ejecutable
target_link_libraries(main PRIVATE raylib)