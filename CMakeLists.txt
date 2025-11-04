cmake_minimum_required(VERSION 3.20)
project(Coding_Practice)
set(CMAKE_CXX_STANDARD 20)

# existing library
add_library(stats_lib STATIC
    exercise-3/stats.cpp
    exercise-3/vector_utils.cpp
)
target_include_directories(stats_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ex4 exercise-4.cpp)
target_link_libraries(ex4 PRIVATE stats_lib)

add_executable(ex5 exercise-5.cpp)

# new target for your marks/ code
add_executable(marks_app
    marks/main.cpp
    marks/student.cpp
    marks/stats.cpp
)
target_include_directories(marks_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
