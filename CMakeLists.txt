cmake_minimum_required(VERSION 2.6)
project(Hildr)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 1.6 REQUIRED system window graphics network audio)

set(EXECUTABLE_NAME "hildr")

file(
    GLOB_RECURSE
    SOURCE_FILES
    src/*
)

add_executable(
    ${EXECUTABLE_NAME}
    ${SOURCE_FILES}
)

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
