#include "Arduino.h"
#include "gpio/gpio.h"
#include "serial/serial.h"
#include "timing/timing.h"

namespace ArduinoMock {
    void reset() {
        TimeMock::reset();
        GpioMock::reset();
        SerialMock::clearWrittenData();
        InterruptsMock::reset();
    }
}