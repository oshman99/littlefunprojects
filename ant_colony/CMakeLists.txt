cmake_minimum_required ( VERSION 3.1.0 )

project(ant_optim)
set (CMAKE_CXX_STANDARD 17)

#Sources
set(ACO_SRC
    src/main.cpp

    src/Graph.h
    src/Graph.cpp
    
    src/Ant.h
    src/Ant.cpp

    src/ACO.h
    src/ACO.cpp
    )

#Executable
add_executable(ant_optim ${ACO_SRC})
include_directories(src/)