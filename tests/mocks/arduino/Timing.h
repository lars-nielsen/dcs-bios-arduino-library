#ifndef ARDUINO_TIMING_MOCK_H
#define ARDUINO_TIMING_MOCK_H

#include <cstdint>

// Timing mock
unsigned long millis();
unsigned long micros();
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);

// Test time control
namespace TimeMock {
    void setCurrentTime(unsigned long ms);
    void advanceTime(unsigned long ms);
    void reset();
}

#endif // ARDUINO_TIMING_MOCK_H