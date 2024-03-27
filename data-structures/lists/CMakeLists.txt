cmake_minimum_required(VERSION 3.10)

project(lists VERSION 0.1.0 LANGUAGES C DESCRIPTION "library of list implementations")

set (LIBRARY_NAME lists_library)

################################################
# Build the Library:
################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(${LIBRARY_NAME} STATIC
    src/single_linked_list.c
)

set_target_properties(${LIBRARY_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER include/single_linked_list.h
)

################################################
# Build the Executable:
################################################

add_executable(${PROJECT_NAME}
    src/example.c
)

target_link_libraries(${PROJECT_NAME}
    ${LIBRARY_NAME}
    vector_library
)