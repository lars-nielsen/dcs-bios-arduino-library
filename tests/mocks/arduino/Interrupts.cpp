// Interrupt mock
#include "Interrupts.h"
#include <cstring>

static void (*interruptHandlers[8])() = {nullptr};
static int interruptModes[8] = {0};
static bool interruptsEnabled = true;

void attachInterrupt(uint8_t interrupt, void (*handler)(), int mode) {
    if (interrupt < 8) {
        interruptHandlers[interrupt] = handler;
        interruptModes[interrupt] = mode;
    }
}

void detachInterrupt(uint8_t interrupt) {
    if (interrupt < 8) {
        interruptHandlers[interrupt] = nullptr;
        interruptModes[interrupt] = 0;
    }
}

void noInterrupts() {
    interruptsEnabled = false;
}

void interrupts() {
    interruptsEnabled = true;
}

uint8_t digitalPinToInterrupt(uint8_t pin) {
    // For testing, we can just return the pin number as the interrupt number
    return pin;
}

// Test control
namespace InterruptsMock {
    void reset() {
        std::memset(interruptHandlers, 0, sizeof(interruptHandlers));
        std::memset(interruptModes, 0, sizeof(interruptModes));
        interruptsEnabled = true;
    }
    
    void triggerInterrupt(uint8_t interrupt) {
        if (interrupt < 8 && interruptHandlers[interrupt] != nullptr && interruptsEnabled) {
            interruptHandlers[interrupt]();
        }
    }
    
    bool areInterruptsEnabled() {
        return interruptsEnabled;
    }
    
    void (*getHandler(uint8_t interrupt))() {
        if (interrupt < 8) {
            return interruptHandlers[interrupt];
        }
        return nullptr;
    }
    
    int getMode(uint8_t interrupt) {
        if (interrupt < 8) {
            return interruptModes[interrupt];
        }
        return 0;
    }
}