cmake_minimum_required(VERSION 3.13)

project(statemachine-test)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
#add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

add_executable(statemachine-test
    ../src/statemachine.c
    test.cpp)

target_include_directories(statemachine-test
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-src/googletest/include
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-src/googlemock/include
    )

target_link_libraries(statemachine-test
    PRIVATE
    gtest_main)
