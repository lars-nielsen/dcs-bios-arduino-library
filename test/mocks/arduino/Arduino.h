#ifndef ARDUINO_H
#define ARDUINO_H

#include "arduino/serial/serial.h"
#include "arduino/interrupts/interrupts.h"
#include "arduino/gpio/gpio.h"
#include "arduino/timing/timing.h"

#ifndef NULL
#define NULL 0
#endif

// Mock Arduino types and constants
typedef uint8_t byte;
typedef unsigned int word;

namespace ArduinoMock {
    void reset();
}

#endif