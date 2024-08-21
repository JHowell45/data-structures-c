cmake_minimum_required(VERSION 3.10)

project(data-structures VERSION 0.1.0 LANGUAGES C DESCRIPTION "Custom data types and structures written in C")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

################################################
# Set Variables:
################################################

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data-structures)
set(INCLUDE ${ROOT_DIR}/include)
set(SRC ${ROOT_DIR}/src)
set(EXAMPLES ${ROOT_DIR}/examples)

set(LIBRARY jacob-algos)

set(VECTOR_EXAMPLE vector_example)
set(LINKED_LIST_EXAMPLE lists_example)
set(TREE_EXAMPLE trees_example)

################################################
# Build the Libraries:
################################################

include_directories(${INCLUDE})

add_library(${LIBRARY} SHARED 
    ${SRC}/vector.c
    ${SRC}/single_linked_list.c
)
set_target_properties(${LIBRARY} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER ${INCLUDE}/*.h
)

################################################
# Build the Executables:
################################################

add_executable(${VECTOR_EXAMPLE} ${EXAMPLES}/vector.c)
target_link_libraries(${VECTOR_EXAMPLE} ${LIBRARY})

add_executable(${LINKED_LIST_EXAMPLE} ${EXAMPLES}/single_linked_list.c)
target_link_libraries(${LINKED_LIST_EXAMPLE} ${LIBRARY})