cmake_minimum_required(VERSION 3.4)

project(stl2glb CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<1:${PROJECT_SOURCE_DIR}/bin/$<CONFIG>>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${PROJECT_SOURCE_DIR}/bin/$<CONFIG>>)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(./fmt EXCLUDE_FROM_ALL)
add_subdirectory(./lxd lxd)
add_subdirectory(./src ${PROJECT_NAME})

set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})