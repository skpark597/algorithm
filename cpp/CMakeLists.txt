cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")	
set(YEAR_MONTH 2021_10)
set(FILE_NAME LongestIncreasingSubsequence.cc)

project(algorithm)

file(GLOB SRC_FILES
	./${YEAR_MONTH}/${FILE_NAME}
)

include_directories(${CMAKE_SOURCE_DIR}/common)

add_subdirectory(common)
add_executable(algorithm ${SRC_FILES})
target_link_libraries(algorithm PUBLIC common)



