#include "timing.h"

static unsigned long currentTime = 0;

unsigned long millis() {
    return currentTime;
}

unsigned long micros() {
    return currentTime * 1000;
}

void delay(unsigned long ms) {
    currentTime += ms;
}

void delayMicroseconds(unsigned int us) {
    currentTime += us / 1000;
}

// Test time control
namespace TimeMock {
    void setCurrentTime(unsigned long ms) {
        currentTime = ms;
    }
    
    void advanceTime(unsigned long ms) {
        currentTime += ms;
    }
    
    void reset() {
        currentTime = 0;
    }
}