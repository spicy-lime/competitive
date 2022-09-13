cmake_minimum_required(VERSION 3.12.0)
project(emu VERSION 0.1.0)

include(CTest)
enable_testing()
set_property(GLOBAL PROPERTY CXX_STANDARD 20) 
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED true) 
set_property(GLOBAL PROPERTY CMAKE_BUILD_TYPE Debug)

include_directories(inc) 
add_subdirectory(inc)

file(GLOB srcs src/*.cpp)
list(APPEND srcs "main.cpp")

file(GLOB tests tests/*.cpp)
list(APPEND tests ${srcs})
list(APPEND tests "testmain.cpp")
list(REMOVE_ITEM tests "main.cpp")
add_executable(main ${srcs})
set_property(TARGET main PROPERTY CXX_STANDARD 20)

add_subdirectory(googletest)
include_directories(googletest/googletest/include) # this is so we can #include <gtest/gtest.h>
add_executable(tests ${tests})
set_property(TARGET tests PROPERTY CXX_STANDARD 20)
target_link_libraries(tests PRIVATE gtest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)