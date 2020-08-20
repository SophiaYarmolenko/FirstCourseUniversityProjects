cmake_minimum_required(VERSION 3.15)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator main.cpp MathAction.cpp MathAction.h Number.cpp Number.h Trie.cpp Trie.h Operation.cpp Operation.h)