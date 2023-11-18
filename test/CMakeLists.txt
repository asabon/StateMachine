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

enable_testing()

add_executable(
  statemachine-test
  ../src/statemachine.c
  test.cpp)

include(
  GoogleTest
  GoogleMock)

gtest_discover_tests(statemachine-test)
