cmake_minimum_required(VERSION 2.6)
project(LoZ-Clone)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(SFML_ROOT ${CMAKE_SOURCE_DIR}/SFML)

IF(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
ELSE(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF(APPLE)




find_package(SFML COMPONENTS graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

file(GLOB SRCS *.cpp *.h *.hpp)

add_executable(exe main.cpp ${SRCS})
target_link_libraries(exe ${SFML_LIBRARIES})
