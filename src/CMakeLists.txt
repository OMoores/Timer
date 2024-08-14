add_subdirectory(testing)

add_library(
    Timer
    timer.cpp
    timer.h
)

target_include_directories(Timer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})