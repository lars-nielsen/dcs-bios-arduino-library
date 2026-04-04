#ifndef ARDUINO_GPIO_MOCK_H
#define ARDUINO_GPIO_MOCK_H

#include <cstdint>

// Pin modes
#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

// Digital levels
#define LOW 0x0
#define HIGH 0x1

// GPIO arrays (defined in gpio.cpp)
extern uint8_t pinModes[256];
extern uint8_t pinValues[256];

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
int analogRead(uint8_t pin);
void analogWrite(uint8_t pin, int val);

namespace GpioMock {
    void reset();
}

#endif // ARDUINO_GPIO_MOCK_H