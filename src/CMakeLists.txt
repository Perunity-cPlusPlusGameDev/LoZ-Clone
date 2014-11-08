cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

project(LoZ-Clone)

find_package(SFML REQUIRED COMPONENTS graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

add_executable(exe main.cpp)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/SFML)
target_link_libraries(${project_name} ${FEATHERKIT_LIBRARIES} ${SFML_LIBRARIES})
