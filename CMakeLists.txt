cmake_minimum_required (VERSION 3.1)
project (Park)

# Update include/park/version.h when changing the numbers below.
set (Park_VERSION_MAJOR 0)
set (Park_VERSION_MINOR 1)
set (Park_VERSION_PATCH 0)

# This project requires C++11.
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

configure_file(
    "${PROJECT_SOURCE_DIR}/src/test/version_unittest.cpp.in"
    "${PROJECT_BINARY_DIR}/src/test/version_unittest.cpp"
)

option (PARK_BUILD_TESTS "Build Park's unit test" ON)

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/src"
)

add_library(park "")
target_sources(park
PRIVATE
    "${PROJECT_SOURCE_DIR}/src/api/rpcclient.cpp"
PUBLIC
    "${PROJECT_SOURCE_DIR}/include/park/function.h"
    "${PROJECT_SOURCE_DIR}/include/park/mode.h"
    "${PROJECT_SOURCE_DIR}/include/park/network.h"
    "${PROJECT_SOURCE_DIR}/include/park/parameter.h"
    "${PROJECT_SOURCE_DIR}/include/park/rpcclient.h"
    "${PROJECT_SOURCE_DIR}/include/park/rpcserver.h"
    "${PROJECT_SOURCE_DIR}/include/park/status.h"
    "${PROJECT_SOURCE_DIR}/include/park/version.h"
)

if (PARK_BUILD_TESTS)
    enable_testing()
    add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/googletest")
    add_executable(park_tests "")
    target_sources(park_tests
    PRIVATE 
        "${PROJECT_BINARY_DIR}/src/test/status_unittest.cpp"
        "${PROJECT_SOURCE_DIR}/src/test/test_main.cpp"
        "${PROJECT_BINARY_DIR}/src/test/version_unittest.cpp"
    )
    target_link_libraries(park_tests park gtest)
    add_test(NAME park_tests COMMAND park_tests)
endif(PARK_BUILD_TESTS)
