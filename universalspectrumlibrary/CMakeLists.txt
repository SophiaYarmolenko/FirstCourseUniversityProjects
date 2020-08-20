cmake_minimum_required(VERSION 3.15)
project(universalspectrum)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp universalspectrum.cpp universalspectrum.hpp)

add_library(universalspectrum ${SOURCE_FILES})
