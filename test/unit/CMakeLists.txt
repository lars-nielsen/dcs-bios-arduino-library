# Example test executable
add_executable(dcsbios_tests
    ProtocolTest.cpp
    ButtonsTest.cpp
    # Add more test files here as needed
    # ButtonsTest.cpp
    # SerializationTest.cpp
)

target_include_directories(dcsbios_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../mocks
    ${LIB_INCLUDE_DIRS}
)

target_link_libraries(dcsbios_tests PRIVATE
    gtest_main
    ArduinoMock
    DcsMock
)

# Make gtest_discover_tests available
include(GoogleTest)

gtest_discover_tests(dcsbios_tests)
