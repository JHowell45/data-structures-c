cmake_minimum_required(VERSION 3.10)

project(vector VERSION 0.1.0 LANGUAGES C DESCRIPTION "Basic vector, (dynamic resizing array) implementation")

set (LIBRARY_NAME vector_library)

################################################
# Build the Library:
################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(${LIBRARY_NAME} STATIC
    src/vector.c
)

set_target_properties(${LIBRARY_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER include/vector.h
)

################################################
# Build the Executable:
################################################

add_executable(vector_example
    src/example.c
)

target_link_libraries(vector_example
    ${LIBRARY_NAME}
)