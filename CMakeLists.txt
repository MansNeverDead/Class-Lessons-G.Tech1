cmake_minimum_required(VERSION 3.10.0)
project(ClassDiving VERSION 0.1.0 LANGUAGES C CXX)

add_executable(ClassDiving ClassDiving.cpp)

include(CTest)
enable_testing()