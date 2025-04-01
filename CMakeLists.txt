# set(CMAKE_C_COMPILER "gcc")
# set(CMAKE_CXX_STANDARD 12)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")

cmake_minimum_required(VERSION 3.25)

project(
    secrecy
    LANGUAGES CXX C
)

include(CTest)

set(CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#################
## Main Library
#################

add_library(
    "${PROJECT_NAME}"
    SHARED
    "src/cpp_secrecy.cpp"
    "src/c_secrecy.c"
)

target_include_directories(
    "${PROJECT_NAME}" 
    PRIVATE 
    "include"
)

target_link_libraries(
    "${PROJECT_NAME}"
    PUBLIC
    "crypto"
)

## Tests
add_subdirectory("${PROJECT_SOURCE_DIR}/tests/cpp_tests/unit")
add_subdirectory("${PROJECT_SOURCE_DIR}/tests/c_tests/unit")

## Examples
add_subdirectory("${PROJECT_SOURCE_DIR}/examples/cpp/basic")
add_subdirectory("${PROJECT_SOURCE_DIR}/examples/cpp/cpp_using_c_secrecy")
add_subdirectory("${PROJECT_SOURCE_DIR}/examples/c/basic")
