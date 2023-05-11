cmake_minimum_required(VERSION 3.21.1)
project(Google_tests)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(
        googletest

        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
add_executable(Google_Tests_run model/tests/test_calculate.cc
        model/calculate.cc model/calculate.h
        model/validation.h model/validation.cc
        model/parser.cc model/parser.h)

target_link_libraries(Google_Tests_run gtest gtest_main)