cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME jacob-algos)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C DESCRIPTION "Custom data types and structures written in C")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

####################################################################################
# Set Variables:
####################################################################################

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data-structures)
file(GLOB SOURCES ${ROOT_DIR}/src/*.c)
file(GLOB HEADERS ${ROOT_DIR}/include/*.h)

####################################################################################
# Build the Libraries:
####################################################################################

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${ROOT_DIR}/include)

# set_target_properties(${PROJECT_NAME} PROPERTIES
#     VERSION ${PROJECT_VERSION}
#     SOVERSION ${PROJECT_VERSION_MAJOR}
#     PUBLIC_HEADER ${INCLUDE}/*.h
# )


####################################################################################
# Install Test Framework:
####################################################################################
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        b514bdc898e2951020cbdca1304b75f5950d1f59 # release-1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

####################################################################################
#  Tests:
####################################################################################
set(TESTS_DIR tests)

add_executable(test_single_linked_lists ${TESTS_DIR}/single_linked_lists.c)
target_link_libraries(test_single_linked_lists 
    ${PROJECT_NAME}
    GTest::gtest_main
)

enable_testing()

include(GoogleTest)
gtest_discover_tests(test_single_linked_lists)

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