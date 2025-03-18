# set(CMAKE_C_COMPILER "gcc")
# set(CMAKE_CXX_STANDARD 12)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")

cmake_minimum_required(VERSION 3.25)

project(
    cpp_secrecy
    LANGUAGES CXX
)

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

### Unit Tests 

add_executable(
    "${PROJECT_NAME}_unit_tests"
    "${PROJECT_SOURCE_DIR}/tests/unit/src/test_cpp_secrecy.cpp"
    "${PROJECT_SOURCE_DIR}/tests/unit/src/test_cpp_secrecy_int.cpp"
    "${PROJECT_SOURCE_DIR}/tests/unit/src/test_cpp_secrecy_array.cpp"
)

target_include_directories(
    "${PROJECT_NAME}_unit_tests" 
    PRIVATE 
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/tests/unit/include"
)

target_link_directories(
    "${PROJECT_NAME}_unit_tests" 
    PUBLIC 
    "${PROJECT_SOURCE_DIR}/lib"
    "/usr/lib/x86_64-linux-gnu/"
)

target_link_libraries(
    "${PROJECT_NAME}_unit_tests" 
    PUBLIC
    "cunit"
    "cpp_secrecy"
)