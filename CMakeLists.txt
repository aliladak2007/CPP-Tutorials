cmake_minimum_required(VERSION 3.20)
project(Coding_Practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ============================================================
# PRICING LIBRARY (build ALL pricing classes once)
# ============================================================

file(GLOB PRICING_SOURCES
    "pricing/*.cpp"
)

add_library(pricing_lib ${PRICING_SOURCES} "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_include_directories(pricing_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# ============================================================
# STATS LIB (exercise 3)
# ============================================================

add_library(stats_lib STATIC
    exercise-3/stats.cpp
    exercise-3/vector_utils.cpp
 "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_include_directories(stats_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# ============================================================
# Top-level exercises (each has its own main)
# ============================================================

add_executable(ex1 exercise-1.cpp "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_link_libraries(ex1 PRIVATE pricing_lib)

add_executable(ex2 exercise-2.cpp "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_link_libraries(ex2 PRIVATE pricing_lib)

add_executable(ex4 exercise-4.cpp "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_link_libraries(ex4 PRIVATE stats_lib pricing_lib)

add_executable(ex5 exercise-5.cpp "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_link_libraries(ex5 PRIVATE pricing_lib)

# ============================================================
# EXERCISE 6 (main + helper files)
# ============================================================

add_executable(ex6
    exercise-6/main.cpp
    exercise-6/student.cpp
    exercise-6/stats.cpp
 "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_link_libraries(ex6 PRIVATE pricing_lib)

# ============================================================
# EXERCISE 7
# ============================================================

add_executable(ex7_q1 exercise-7/q1.cpp "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_link_libraries(ex7_q1 PRIVATE pricing_lib)

add_executable(ex7_products
    exercise-7/products/main.cpp
    exercise-7/products/product.cpp
    exercise-7/products/book.cpp
    exercise-7/products/cd.cpp
    exercise-7/products/pound_product.cpp
 "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
target_link_libraries(ex7_products PRIVATE pricing_lib)

# ============================================================
# FURTHER EXERCISES WEEK 6
# ============================================================

file(GLOB FE_W6_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Further-Exercises/week6/*.cpp"
)

foreach(src ${FE_W6_SOURCES})
    get_filename_component(base "${src}" NAME_WE)
    add_executable(fe_${base} "${src}" "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
    target_link_libraries(fe_${base} PRIVATE pricing_lib)
endforeach()

# ============================================================
# FURTHER EXERCISES WEEK 7
# ============================================================

file(GLOB FE_W7_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Further-Exercises/week7/*.cpp"
)

foreach(src ${FE_W7_SOURCES})
    get_filename_component(base "${src}" NAME_WE)
    add_executable(fe7_${base} "${src}" "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
    target_link_libraries(fe7_${base} PRIVATE pricing_lib)
endforeach()

# ============================================================
# TEST MAIN INSIDE PRICING/
# ============================================================

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/pricing/main.cpp")
    add_executable(main_app pricing/main.cpp "pricing/limited-reduction-pricing.h" "pricing/limited-reduction-pricing.cpp")
    target_link_libraries(main_app PRIVATE pricing_lib)
endif()
