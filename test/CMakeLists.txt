cmake_minimum_required(VERSION 3.28)
project(Gabri_sInvaders_test)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(runAllTests runAllTests.cpp
        testEntity.cpp
        testShip.cpp
        testAlien.cpp
)

target_link_libraries(runAllTests gtest_main GameEngine)

set_target_properties(runAllTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/")
