cmake_minimum_required(VERSION 3.10)

project(task2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD_REQUIRED on)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(
    ../include
    ${GTEST_INCLUDE_DIRS}
)

include_directories(A)
add_subdirectory(B)
execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)

add_executable (C C/main.cpp C/main.h)
add_executable(CTest C/main_test.cpp)

target_link_libraries(C B_lib)
target_include_directories(C PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries(CTest B_lib)
target_include_directories(CTest PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries (CTest ${GTEST_LIBRARIES} Threads::Threads)