cmake_minimum_required(VERSION 2.6)
project(LoZ-Clone)

add_executable(exe main.cpp)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/SFML)
TARGET_LINK_LIBRARIES(exe sfml-graphics)
