
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

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
