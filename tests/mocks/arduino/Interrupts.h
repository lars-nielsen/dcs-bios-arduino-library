#ifndef ARDUINO_INTERRUPTS_MOCK_H
#define ARDUINO_INTERRUPTS_MOCK_H

#include <cstdint>

void attachInterrupt(uint8_t interrupt, void (*handler)(), int mode);
void detachInterrupt(uint8_t interrupt);
void noInterrupts();
void interrupts();

// Test control
namespace InterruptsMock {
    void reset();
}

#endif // ARDUINO_INTERRUPTS_MOCK_H