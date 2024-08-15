add_executable(
    Test_Timer
    Test_Timer.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

target_link_libraries(
    Test_Timer
    GTest::gtest_main
    Timer
)

gtest_discover_tests(Test_Timer)