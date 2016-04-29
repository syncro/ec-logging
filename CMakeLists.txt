cmake_minimum_required(VERSION 3.0)
project (ec-logging)


set(BOND_VERSION_MAJOR 1)
set(BOND_VERSION_MINOR 0)
set(CMAKE_BUILD_TYPE Debug)
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_BUILD_TYPE Debug)

OPTION(BUILD_TEST "Build the tests" FALSE)

# Conan Package Manager
include(conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


add_library(${PROJECT_NAME} INTERFACE)


target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_link_libraries(${PROJECT_NAME} INTERFACE ${CONAN_LIBS})

target_compile_features(${PROJECT_NAME} INTERFACE cxx_range_for)

if(BUILD_TEST)
	add_executable(run_test src/test.cpp)
	target_link_libraries(run_test ${CONAN_LIBS})
endif()



