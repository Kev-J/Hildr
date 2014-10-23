cmake_minimum_required(VERSION 2.6)
project(Hildr)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 1.6 REQUIRED system window graphics network audio)
find_package(SFGUI REQUIRED)
find_package(OpenGL REQUIRED)

add_definitions(-std=c++11)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
