#include "Arduino.h"
#include "Gpio.h"
#include "Serial.h"
#include "Timing.h"
#include "Interrupts.h"

namespace ArduinoMock {
    void reset() {
        TimeMock::reset();
        GpioMock::reset();
        SerialMock::clearWrittenData();
        InterruptsMock::reset();
    }
}