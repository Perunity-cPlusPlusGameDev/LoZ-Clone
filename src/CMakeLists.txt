cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(SFML_ROOT ${CMAKE_SOURCE_DIR}/SFML)
set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

project(LoZ-Clone)

find_package(SFML REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
add_executable(exe main.cpp ${SFML_INCLUDE_DIR}/Graphics.hpp)
target_link_libraries(exe ${SFML_LIBRARIES})
