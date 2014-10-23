set(EXECUTABLE_NAME "hildr")

include_directories( ${SFGUI_INCLUDE_DIR} )
include_directories(${OPENGL_INCLUDE_DIR})

file(
    GLOB_RECURSE
    SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*
)

add_executable(
    ${EXECUTABLE_NAME}
    ${SOURCE_FILES}
)

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFGUI_LIBRARY} ${OPENGL_LIBRARIES})
