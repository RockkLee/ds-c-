cmake_minimum_required(VERSION 3.0.0)
project(big-o VERSION 0.1.0 LANGUAGES C CXX)

# set(ROOT_PATH "${CMAKE_SOURCE_DIR}")

# Glob all source files
file(GLOB SOURCES "src/*.cpp")
# Glob all test source files
file(GLOB TEST_SOURCES "tests/*.cpp")

# Define MY_SOURCES to be a list of all the source files for my project
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(app "${MY_SOURCES}")

add_subdirectory(src)
add_subdirectory(tests)

# Enable testing
enable_testing()

# use google test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
