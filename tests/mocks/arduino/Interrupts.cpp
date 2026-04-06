// Interrupt mock
#include "Interrupts.h"
#include <cstring>

static void (*interruptHandlers[8])() = {nullptr};

void attachInterrupt(uint8_t interrupt, void (*handler)(), int mode) {
    if (interrupt < 8) {
        interruptHandlers[interrupt] = handler;
    }
}

void detachInterrupt(uint8_t interrupt) {
    if (interrupt < 8) {
        interruptHandlers[interrupt] = nullptr;
    }
}

void noInterrupts() {
    // Mock implementation
}

void interrupts() {
    // Mock implementation
}

// Test control
namespace InterruptsMock {
    void reset() {
        std::memset(interruptHandlers, 0, sizeof(interruptHandlers));
    }
}