# include(AddGoogleTest)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    all_tests
    TestExample.cpp
)
target_include_directories(all_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(
    all_tests PRIVATE bigodemo GTest::gtest_main
)

# Enable CTest testing
include(GoogleTest)
gtest_discover_tests(all_tests)