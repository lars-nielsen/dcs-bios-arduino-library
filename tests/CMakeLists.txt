# DCS-BIOS Arduino Library Tests
cmake_minimum_required(VERSION 3.15)
project(dcs-bios-arduino-library-tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../src)

# Fetch Google Test from GitHub
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# ============================================================================
# DCS Mock Library
# ============================================================================
add_library(DcsMock
    mocks/dcs/DcsMock.cpp
)

target_include_directories(DcsMock PUBLIC
    mocks/arduino
    ${LIB_INCLUDE_DIRS}
)

# ============================================================================
# Arduino Mock Library
# ============================================================================
add_library(ArduinoMock
    mocks/arduino/Arduino.cpp
    mocks/arduino/Gpio.cpp
    mocks/arduino/Serial.cpp
    mocks/arduino/Interrupts.cpp
    mocks/arduino/Timing.cpp
)

target_include_directories(ArduinoMock PRIVATE
)

# ============================================================================
# Test Executable
# ============================================================================
add_executable(dcsbios_tests
    unit/ArduinoMockTest.cpp
    unit/ButtonsTest.cpp
)

target_include_directories(dcsbios_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks/arduino
    ${LIB_INCLUDE_DIRS}
)

target_link_libraries(dcsbios_tests PRIVATE
    gtest_main
    ArduinoMock
    DcsMock
)

# ============================================================================
# Test Discovery
# ============================================================================
include(GoogleTest)

gtest_discover_tests(dcsbios_tests)
