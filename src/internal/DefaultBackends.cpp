#include <cstdint>
#include <Arduino.h>
#include "Backends.cpp"

namespace DcsBios {
    static uint16_t defaultAnalogRead(uint8_t pin) {
        return analogRead(pin);
    }

    static int defaultDigitalRead(uint8_t pin) {
        return digitalRead(pin);
    }

    static void defaultPullUpPinMode(uint8_t pin) {
        pinMode(pin, INPUT_PULLUP);
    }

    static const AnalogBackend DefaultPullUpAnalogBackend = {
        defaultAnalogRead,
        defaultPullUpPinMode
    };

    static const DigitalBackend DefaultPullUpDigitalBackend = {
        defaultDigitalRead,
        defaultPullUpPinMode
    };
}