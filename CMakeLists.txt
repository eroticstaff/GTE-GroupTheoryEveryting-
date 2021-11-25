cmake_minimum_required(VERSION 3.20)
project(GroupTheory)

set(CMAKE_CXX_STANDARD 23)

add_executable(
    GroupTheory 
    src/main.cpp 
    src/LinearAlgebra.cpp 
    src/LinearAlgebra.h 
    src/GroupTheory.cpp 
    src/GroupTheory.h 
    src/AlgebraUtils.cpp 
    src/AlgebraUtils.h 
    src/GroupTheoryUtils.h 
    src/GroupTheoryUtils.cpp)
