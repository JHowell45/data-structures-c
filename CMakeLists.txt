cmake_minimum_required(VERSION 3.10)

project(data-structures VERSION 0.1.0 LANGUAGES C DESCRIPTION "Custom data types and structures written in C")

################################################
# Set Variables:
################################################

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data-structures)
set(INCLUDE ${ROOT_DIR}/include)
set(SRC ${ROOT_DIR}/src)
set(EXAMPLES ${ROOT_DIR}/examples)
set(VECTOR_LIBRARY vector)
set(VECTOR_EXAMPLE vector_example)
set(LINKED_LIST_LIBRARY linked_list)
set(LINKED_LIST_EXAMPLE linked_list_example)

################################################
# Build the Libraries:
################################################

include_directories(${INCLUDE})

add_library(${VECTOR_LIBRARY} SHARED ${SRC}/vector.c)
set_target_properties(${VECTOR_LIBRARY} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${INCLUDE}/vector.h
)

add_library(${LINKED_LIST_LIBRARY} SHARED 
    ${SRC}/single_linked_list.c
)
set_target_properties(${LINKED_LIST_LIBRARY} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${INCLUDE}/single_linked_list.h
)

################################################
# Build the Executables:
################################################

add_executable(${VECTOR_EXAMPLE} ${EXAMPLES}/vector.c)
target_link_libraries(${VECTOR_EXAMPLE} ${VECTOR_LIBRARY})

add_executable(${LINKED_LIST_EXAMPLE} ${EXAMPLES}/single_linked_list.c)
target_link_libraries(${LINKED_LIST_EXAMPLE} ${LINKED_LIST_LIBRARY})