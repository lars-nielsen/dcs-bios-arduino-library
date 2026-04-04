cmake_minimum_required(VERSION 3.15)
project(dcs-bios-arduino-library)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for the library
set(LIB_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add test subdirectory
enable_testing()
add_subdirectory(test)
