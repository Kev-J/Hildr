include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include/hildr-map )
include_directories(${SFML_INCLUDE_DIR})

include_directories(${HILDR_LIB_TOOLS_INCLUDE_DIR})

set(HILDR_LIB_MAP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

file(
    GLOB_RECURSE
    SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*
)

add_library(
    "hildr-map"
    SHARED
    ${SOURCE_FILES}
)
