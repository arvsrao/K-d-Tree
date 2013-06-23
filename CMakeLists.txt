cmake_minimum_required(VERSION 2.6)
project(kdtree)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin) 
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-std=c++11")

ADD_EXECUTABLE( main main.cpp)
TARGET_LINK_LIBRARIES( main )

ADD_EXECUTABLE( makendpoints makeNdPoints.cpp)
TARGET_LINK_LIBRARIES( makendpoints )