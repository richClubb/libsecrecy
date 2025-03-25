# set(CMAKE_C_COMPILER "gcc")
# set(CMAKE_CXX_STANDARD 12)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")

cmake_minimum_required(VERSION 3.25)

project(
    cpp_secrecy
    LANGUAGES CXX
)

include(CTest)

set(CXX_STANDARD 11)

#################
## Main Library
#################

add_library(
    "${PROJECT_NAME}"
    SHARED
    "src/cpp_secrecy.cpp"
)

target_include_directories(
    "${PROJECT_NAME}" 
    PRIVATE 
    "include"
)

add_custom_command(
    TARGET 
    "${PROJECT_NAME}" 
    POST_BUILD
    COMMAND 
    ${CMAKE_COMMAND} -E copy "lib/lib${PROJECT_NAME}.so" "${PROJECT_SOURCE_DIR}/lib/"
)

add_subdirectory("${PROJECT_SOURCE_DIR}/tests/unit")
