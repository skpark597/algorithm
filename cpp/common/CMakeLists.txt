cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")	

file(GLOB COMMON_FILES
	*.cc
)

add_library(common SHARED ${COMMON_FILES})

