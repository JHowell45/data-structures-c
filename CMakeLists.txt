cmake_minimum_required(VERSION 3.10)

project(data-structures VERSION 0.1.0 LANGUAGES C DESCRIPTION "Custom data types and structures written in C")

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data-structures)

add_subdirectory(${ROOT_DIR}/hashtable)
add_subdirectory(${ROOT_DIR}/lists)
add_subdirectory(${ROOT_DIR}/trees)
add_subdirectory(${ROOT_DIR}/vector)