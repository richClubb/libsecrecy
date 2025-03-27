# set(CMAKE_C_COMPILER "gcc")
# set(CMAKE_CXX_STANDARD 12)

cmake_minimum_required(VERSION 3.25)

project(
    cpp_secrecy_basic_example
    LANGUAGES CXX
)

include(CTest)

set(CXX_STANDARD 11)

#################
## Unit Tests 
#################

add_executable(
    "${PROJECT_NAME}"
    "main.cpp"
)

target_include_directories(
    "${PROJECT_NAME}" 
    PRIVATE 
    "${PROJECT_SOURCE_DIR}/../../include"
)

target_link_directories(
    "${PROJECT_NAME}" 
    PUBLIC 
    "${PROJECT_SOURCE_DIR}/../../build/lib"
)

target_link_libraries(
    "${PROJECT_NAME}" 
    PUBLIC
    "cpp_secrecy"
)

