#ifndef ARDUINO_H
#define ARDUINO_H

#include <cstdint>
#include "Serial.h"
#include "Gpio.h"
#include "Timing.h"
#include "Interrupts.h"

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