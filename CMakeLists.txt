cmake_minimum_required(VERSION 3.20)
project(main)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main
        main.cpp
        dbscan.cpp
        dbscan.h)
target_link_libraries(main)

# target_include_directories(dbscan PUBLIC
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/eigen>
#         )