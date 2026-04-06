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

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define CHANGE 0x1
#define RISING 0x2
#define FALLING 0x3

#define LOW 0x0 
#define HIGH 0x1

// Mock Arduino types and constants
typedef uint8_t byte;
typedef unsigned int word;

namespace ArduinoMock {
    void reset();
}

#endif