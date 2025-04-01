# set(CMAKE_C_COMPILER "gcc")
# set(CMAKE_CXX_STANDARD 12)

 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")

cmake_minimum_required(VERSION 3.25)

project(
    cpp_secrecy_unit_tests
    LANGUAGES CXX
)

include(CTest)

set(CXX_STANDARD 11)

#################
## Unit Tests 
#################

add_executable(
    "${PROJECT_NAME}"
    "${PROJECT_SOURCE_DIR}/src/test_unit_cpp_secrecy.cpp"
    "${PROJECT_SOURCE_DIR}/src/test_unit_cpp_secrecy_int.cpp"
    "${PROJECT_SOURCE_DIR}/src/test_unit_cpp_secrecy_float.cpp"
    "${PROJECT_SOURCE_DIR}/src/test_unit_cpp_secrecy_array.cpp"
    "${PROJECT_SOURCE_DIR}/src/test_unit_cpp_secrecy_string.cpp"
    "${PROJECT_SOURCE_DIR}/src/test_unit_cpp_secrecy_vector.cpp"
    "${PROJECT_SOURCE_DIR}/src/test_unit_cpp_secrecy_custom_struct.cpp"
)

add_test(NAME "${PROJECT_NAME}" COMMAND "${PROJECT_NAME}")

target_include_directories(
    "${PROJECT_NAME}" 
    PRIVATE 
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/../../../include"
)

target_link_directories(
    "${PROJECT_NAME}" 
    PUBLIC 
    "${PROJECT_SOURCE_DIR}/../../../build/lib"
    "/usr/lib/x86_64-linux-gnu/"
)

target_link_libraries(
    "${PROJECT_NAME}" 
    PUBLIC
    "cunit"
    "secrecy"
)

