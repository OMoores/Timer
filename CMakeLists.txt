cmake_minimum_required(VERSION 3.2)
project(Timer VERSION 1.0)

# Include FetchContent module to download and manage GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Enable testing framework
enable_testing()

# Include GoogleTest module for CMake
include(GoogleTest)

add_subdirectory(src)

