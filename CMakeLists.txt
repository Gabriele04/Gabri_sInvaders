cmake_minimum_required(VERSION 3.28)
project(Gabri_sInvaders)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(GameEngine STATIC src/GameEngine.cpp
        src/Sprite.cpp
        src/Ship.cpp
        src/Alien.cpp
        src/ActiveSprite.cpp)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
target_link_libraries(GameEngine sfml-graphics sfml-window sfml-system)

add_subdirectory(test)

add_executable(Gabri_sInvaders main.cpp)
target_link_libraries(Gabri_sInvaders GameEngine)
