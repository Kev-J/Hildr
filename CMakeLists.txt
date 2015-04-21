cmake_minimum_required(VERSION 2.6)
project(Hildr)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/hildr)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 1.6 REQUIRED system window graphics network audio)
find_package(SFGUI REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Qt4 REQUIRED QtGui QtOpenGL)
find_package(XercesC REQUIRED)

add_definitions(-std=c++11)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR}/usr/share/hildr)
