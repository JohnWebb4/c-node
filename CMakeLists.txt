cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE 
  ./src/index.cpp
)

# Link tests
add_executable(runTests ${SOURCE})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

target_include_directories(runTests PUBLIC src/)
