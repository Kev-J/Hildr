include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )
include_directories(${XERCESC_INCLUDE_DIRS})
include_directories(${SFML_INCLUDE_DIR})

set(HILDR_LIB_TOOLS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

file(
    GLOB_RECURSE
    SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(
    "hildr-tools"
    SHARED
    ${SOURCE_FILES}
)
