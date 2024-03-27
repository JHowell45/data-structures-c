cmake_minimum_required(VERSION 3.10)

project(trees VERSION 0.1.0 LANGUAGES C DESCRIPTION "library of tree implementations")

set (LIBRARY_NAME trees_library)

################################################
# Build the Library:
################################################

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# add_library(${LIBRARY_NAME} SHARED
#     src/binary_tree.c
#     src/btree.c
#     src/heap.c
# )

# set_target_properties(${LIBRARY_NAME} PROPERTIES
#     VERSION ${PROJECT_VERSION}
#     SOVERSION ${PROJECT_VERSION_MAJOR}
#     PUBLIC_HEADER include/binary_tree.h
#     PUBLIC_HEADER include/btree.h
#     PUBLIC_HEADER include/heap.h
# )

################################################
# Build the Executable:
################################################

add_executable(trees_example
    src/example.c
)

# target_link_libraries(trees_example
#     ${LIBRARY_NAME}
# )