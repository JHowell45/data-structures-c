cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME jacob-algos)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C DESCRIPTION "Custom data types and structures written in C")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

################################################
# Set Variables:
################################################

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data-structures)
file(GLOB SOURCES ${ROOT_DIR}/src/*.c)
file(GLOB HEADERS ${ROOT_DIR}/include/*.h)

################################################
# Build the Libraries:
################################################

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${ROOT_DIR}/include)

# set_target_properties(${PROJECT_NAME} PROPERTIES
#     VERSION ${PROJECT_VERSION}
#     SOVERSION ${PROJECT_VERSION_MAJOR}
#     PUBLIC_HEADER ${INCLUDE}/*.h
# )

################################################
# Build the Executables:
################################################

# add_executable(${VECTOR_EXAMPLE} ${EXAMPLES}/vector.c)
# target_link_libraries(${VECTOR_EXAMPLE} ${PROJECT_NAME})

# add_executable(${LINKED_LIST_EXAMPLE} ${EXAMPLES}/single_linked_list.c)
# target_link_libraries(${LINKED_LIST_EXAMPLE} ${PROJECT_NAME})

####################################################################################
#  Installation:
####################################################################################
if (NOT DEFINED ENV{CUSTOM_C_LIBRARY_DEST})
    message(FATAL_ERROR "Please set the CUSTOM_C_LIBRARY_DEST environment variable!")
endif()

set(LIBRARY_DEST $ENV{CUSTOM_C_LIBRARY_DEST}/${PROJECT_NAME})

message("\n############################################# SETUP #############################################\n")
message(LIBRARY_DEST: ${LIBRARY_DEST})
message("\n#################################################################################################\n")

install(TARGETS ${PROJECT_NAME} DESTINATION ${LIBRARY_DEST}/lib)
install(FILES ${HEADERS} DESTINATION ${LIBRARY_DEST}/include)