cmake_minimum_required(VERSION 3.0.0)
project(sort VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)

# set(ROOT_PATH "${CMAKE_SOURCE_DIR}")

# Glob all source files
file(GLOB SOURCES "src/*.cpp")
# Glob all test source files
file(GLOB TEST_SOURCES "tests/*.cpp")

# Define MY_SOURCES to be a list of all the source files for my project
add_executable(app "${SOURCES}")

add_subdirectory(src)