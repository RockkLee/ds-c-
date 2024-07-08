cmake_minimum_required(VERSION 3.0.0)
project(greedy-method VERSION 0.1.0 LANGUAGES C CXX)

# Glob all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
# Glob all test source files
file(GLOB TEST_SOURCES "tests/*.cpp" "tests/**/*.cpp")

# Define MY_SOURCES to be a list of all the source files for my project
add_executable(app "${SOURCES}")

add_subdirectory(src)