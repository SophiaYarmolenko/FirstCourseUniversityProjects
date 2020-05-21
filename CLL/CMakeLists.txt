cmake_minimum_required(VERSION 3.15)
project(CLL)

set(CMAKE_CXX_STANDARD 14)

add_executable(CLL main.cpp CLA.cpp CLA.h History.cpp History.h Command.cpp Command.h)