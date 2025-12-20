#include <cstdint>
#include <Arduino.h>
#include "Backends.cpp"

namespace DcsBios {
    static void defaultPinMode(uint8_t pin, uint8_t mode) {
        pinMode(pin, mode);
    }

    static uint16_t defaultAnalogRead(uint8_t pin) {
        return analogRead(pin);
    }
    static void defaultAnalogWrite(uint8_t pin, uint16_t value) {
        analogWrite(pin, value);
    }
    static const AnalogBackend DefaultAnalogBackend = {
        defaultAnalogRead,
        defaultAnalogWrite,
    
        defaultPinMode
    };

    static int defaultDigitalRead(uint8_t pin) {
        return digitalRead(pin);
    }
    static void defaultDigitalWrite(uint8_t pin, uint8_t value) {
        digitalWrite(pin, value);
    }
    static const DigitalBackend DefaultDigitalBackend = {
        defaultDigitalRead,
        defaultDigitalWrite,

        defaultPinMode
    };
}