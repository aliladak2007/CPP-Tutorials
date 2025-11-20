cmake_minimum_required(VERSION 3.20)
project(Coding_Practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================
# Library from exercise-3 (no main here)
# ============================================================

add_library(stats_lib STATIC
    exercise-3/stats.cpp
    exercise-3/vector_utils.cpp
)
target_include_directories(stats_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# ============================================================
# Top level exercises (single .cpp with main)
# ============================================================

add_executable(ex1
    exercise-1.cpp
)

add_executable(ex2
    exercise-2.cpp
)

add_executable(ex4
    exercise-4.cpp
)
target_link_libraries(ex4 PRIVATE stats_lib)

add_executable(ex5
    exercise-5.cpp
)

# ============================================================
# Exercise 6 app (one main + helper files in exercise-6/)
# ============================================================

add_executable(ex6
    exercise-6/main.cpp
    exercise-6/student.cpp
    exercise-6/stats.cpp
)
target_include_directories(ex6 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ============================================================
# Exercise 7
#   q1.cpp (standalone)
#   products/ (main + product.cpp + book.cpp + cd.cpp + pound_product.cpp)
# ============================================================

add_executable(ex7_q1
    exercise-7/q1.cpp
)
target_include_directories(ex7_q1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ex7_products
    exercise-7/products/main.cpp
    exercise-7/products/product.cpp
    exercise-7/products/book.cpp
    exercise-7/products/cd.cpp
    exercise-7/products/pound_product.cpp
)
target_include_directories(ex7_products PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ============================================================
# Further-Exercises/week6
#   one executable per fe*.cpp (each has its own main)
# ============================================================

file(GLOB FE_W6_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Further-Exercises/week6/*.cpp"
)

foreach(src ${FE_W6_SOURCES})
    get_filename_component(base "${src}" NAME_WE)
    set(target "fe_${base}")
    add_executable(${target} "${src}")
    target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()

# ============================================================
# Further-Exercises/week7
#   one executable per .cpp (each has its own main)
# ============================================================

file(GLOB FE_W7_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Further-Exercises/week7/*.cpp"
)

foreach(src ${FE_W7_SOURCES})
    get_filename_component(base "${src}" NAME_WE)
    # Different prefix so it does not clash with week6
    set(target "fe7_${base}")
    add_executable(${target} "${src}")
    target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endforeach()
