#include "Gpio.h"
#include <cstring>

uint8_t pinModes[256];
uint8_t pinValues[256];

void pinMode(uint8_t pin, uint8_t mode) {
    if (pin < 256) {
        pinModes[pin] = mode;
    }
}

void digitalWrite(uint8_t pin, uint8_t val) {
    if (pin < 256) {
        pinValues[pin] = val;
    }
}

int digitalRead(uint8_t pin) {
    if (pin < 256) {
        return pinValues[pin];
    }
    return 0;
}

int analogRead(uint8_t pin) {
    if (pin < 256) {
        return pinValues[pin];
    }
    return 0;
}

void analogWrite(uint8_t pin, int val) {
    if (pin < 256) {
        pinValues[pin] = val & 0xFF;
    }
}

namespace GpioMock {
    void reset() {
        std::memset(pinModes, 0, sizeof(pinModes));
        std::memset(pinValues, 0, sizeof(pinValues));
    }
}