cmake_minimum_required(VERSION 3.20)
project(GroupTheory)

set(CMAKE_CXX_STANDARD 23)

add_executable(GroupTheory main.cpp LinearAlgebra.cpp LinearAlgebra.h GroupTheory.cpp GroupTheory.h AlgebraUtils.cpp AlgebraUtils.h)
