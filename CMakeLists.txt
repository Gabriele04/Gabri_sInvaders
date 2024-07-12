cmake_minimum_required(VERSION 3.28)
project(Gabri_sInvaders)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_NAME Gabri_sInvaders)
add_executable(Gabri_sInvaders main.cpp
        GameEngine.cpp
        GameEngine.h
        Sprite.cpp
        Sprite.h
        Ship.cpp
        Ship.h
        Alien.cpp
        Alien.h
        ActiveSprite.cpp
        ActiveSprite.h
)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if (SFML_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif ()