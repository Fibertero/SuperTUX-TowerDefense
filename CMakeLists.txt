cmake_minimum_required(VERSION 3.15)
project(main)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

set(CMAKE_C_STANDARD 11) # Requires C11 standard

add_executable(${PROJECT_NAME} main.cpp)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    # Sources
    src/enemy.cpp
    src/menu.cpp
    src/projectile.cpp
    src/tower.cpp
    src/options.cpp
    src/sounds.cpp
    src/textures.cpp
    # Headers
    src/enemy.hpp
    src/menu.hpp
    src/projectile.hpp
    src/tower.hpp
    src/player.hpp
    src/options.hpp
    src/sounds.hpp
    src/textures.hpp
)
target_link_libraries(${PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()