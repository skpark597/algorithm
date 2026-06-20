cmake_minimum_required(VERSION 3.10)

project(algorithm)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(YEAR_MONTH 2026_06)
set(FILE_NAME InsertInterval.cc)

file(GLOB SRC_FILES "./${YEAR_MONTH}/${FILE_NAME}")

include_directories(${CMAKE_SOURCE_DIR}/common)
add_subdirectory(common)

add_executable(algorithm ${SRC_FILES}
    2026_06/InsertInterval.cc)
target_link_libraries(algorithm PUBLIC common)
