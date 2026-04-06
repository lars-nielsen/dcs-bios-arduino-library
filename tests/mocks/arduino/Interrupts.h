#ifndef ARDUINO_INTERRUPTS_MOCK_H
#define ARDUINO_INTERRUPTS_MOCK_H

#include <cstdint>

// https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/
void attachInterrupt(uint8_t interrupt, void (*handler)(), int mode);
void detachInterrupt(uint8_t interrupt);
void noInterrupts();
void interrupts();

// https://docs.arduino.cc/language-reference/en/functions/external-interrupts/digitalPinToInterrupt/
uint8_t digitalPinToInterrupt(uint8_t pin);

// Test control & utilities
namespace InterruptsMock {
    // Reset all interrupt state
    void reset();
    
    // Test utilities - trigger an interrupt handler
    void triggerInterrupt(uint8_t interrupt);
    
    // Check if interrupts are globally enabled
    bool areInterruptsEnabled();
    
    // Get the handler for an interrupt (for testing)
    void (*getHandler(uint8_t interrupt))();
    
    // Get the mode for an interrupt
    int getMode(uint8_t interrupt);
}

#endif // ARDUINO_INTERRUPTS_MOCK_H