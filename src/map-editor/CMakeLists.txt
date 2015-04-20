set(EXECUTABLE_NAME "hildr-map-editor")

include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${XERCESC_INCLUDE_DIRS})

set(HILDR_LIBRARIES_PATH ${CMAKE_SOURCE_DIR}/src/libraries/)

include_directories(${HILDR_LIBRARIES_PATH}/hildr-map/include)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

file(
    GLOB_RECURSE
    SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

file (
    GLOB_RECURSE
    HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

QT4_WRAP_CPP(HEADER_MOC ${HEADER_FILES})

add_executable(
    ${EXECUTABLE_NAME}
    ${SOURCE_FILES}
    ${HEADER_MOC}
)

target_link_libraries(${EXECUTABLE_NAME}
	${SFML_LIBRARIES}
	${OPENGL_LIBRARIES}
	${QT_LIBRARIES}
        ${XERCESC_LIBRARIES}
	hildr-map
	hildr-tools
	)
