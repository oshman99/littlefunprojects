cmake_minimum_required ( VERSION 3.1.0 )

project(line_dist)
set (CMAKE_CXX_STANDARD 17)

#Sources
set(TASK_SRC
    src/lineDistance.cpp
    inc/vec3.hpp
    inc/lineSegment.hpp)

#Executable
add_executable(line_dist ${TASK_SRC})

target_include_directories(line_dist PRIVATE inc/)