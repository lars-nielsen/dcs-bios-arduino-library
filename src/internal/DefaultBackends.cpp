#include <cstdint>
#include <Arduino.h>
#include "Backends.cpp"

namespace DcsBios {

    static void defaultPullUpPinMode(uint8_t pin) {
        pinMode(pin, INPUT_PULLUP);
    }

    static void defaultOutputPinMode(uint8_t pin) {
        pinMode(pin, OUTPUT);
    }

    static uint16_t defaultAnalogRead(uint8_t pin) {
        return analogRead(pin);
    }
    static const AnalogReadBackend DefaultPullUpAnalogReadBackend = {
        defaultAnalogRead,
        defaultPullUpPinMode
    };

    static void defaultAnalogWrite(uint8_t pin, uint16_t value) {
        analogWrite(pin, value);
    }
    static const AnalogWriteBackend DefaultAnalogWriteBackend = {
        defaultAnalogWrite,
        defaultOutputPinMode
    };

    static int defaultDigitalRead(uint8_t pin) {
        return digitalRead(pin);
    }
    static const DigitalReadBackend DefaultPullUpDigitalReadBackend = {
        defaultDigitalRead,
        defaultPullUpPinMode
    };

    static void defaultDigitalWrite(uint8_t pin, uint8_t value) {
        digitalWrite(pin, value);
    }
    static const DigitalWriteBackend DefaultDigitalWriteBackend = {
        defaultDigitalWrite,
        defaultOutputPinMode
    };
}