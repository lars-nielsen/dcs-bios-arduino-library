# Arduino mock library
add_library(ArduinoMock
    arduino.cpp
    gpio/gpio.cpp
    serial/serial.cpp
    interrupts/interrupts.cpp
    timing/timing.cpp
)

target_include_directories(ArduinoMock PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/test/mocks
)

target_link_libraries(ArduinoMock PUBLIC DcsMock)
