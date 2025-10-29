cmake_minimum_required(VERSION 3.20)
project(Coding_Practice)
set(CMAKE_CXX_STANDARD 20)

# Build a reusable library from exercise-3 implementation files
add_library(stats_lib STATIC
    exercise-3/stats.cpp
    exercise-3/vector_utils.cpp
)

target_include_directories(stats_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Executables that use the stats code
add_executable(ex4 exercise-4.cpp)
target_link_libraries(ex4 PRIVATE stats_lib)

add_executable(ex5 exercise-5.cpp)
# ex5 does not need stats_lib; leave it unlinked unless needed

# If you want an ex3 executable, add a source that contains main, then link:
# add_executable(ex3 exercise-3/main.cpp)
# target_link_libraries(ex3 PRIVATE stats_lib)