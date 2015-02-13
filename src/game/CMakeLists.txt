set(EXECUTABLE_NAME "hildr")

include_directories( ${SFGUI_INCLUDE_DIR} )
include_directories(${OPENGL_INCLUDE_DIR})

set(HILDR_LIBRARIES_PATH ${CMAKE_SOURCE_DIR}/src/libraries/)

include_directories(${HILDR_LIBRARIES_PATH}/hildr-map/include)
message(${HILDR_LIBRARIES_PATH})

file(
    GLOB_RECURSE
    SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*
)

add_executable(
    ${EXECUTABLE_NAME}
    ${SOURCE_FILES}
)

target_link_libraries(${EXECUTABLE_NAME}
	${SFML_LIBRARIES}
	${SFGUI_LIBRARY}
	${OPENGL_LIBRARIES}
	hildr-map
	)
