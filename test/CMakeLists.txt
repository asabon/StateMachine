cmake_minimum_required(VERSION 3.14)
project(statemachine-test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")               # add coverage option
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage") # add coverage option

# Use GoogleTest v1.14.0 (f8d7d77c06936315286eb55f8de22cd23c188571)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  statemachine-test
  ../src/statemachine.c
  test.cpp
)

#target_include_directories(statemachine-test
#  PRIVATE
#    googletest/include
#    googlemock/include
#)

target_link_libraries(
  statemachine-test
  GTest::gtest_main 
)

include(
  GoogleTest
)

gtest_discover_tests(statemachine-test)
