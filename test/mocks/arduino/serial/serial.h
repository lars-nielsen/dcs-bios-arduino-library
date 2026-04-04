#ifndef ARDUINO_SERIAL_MOCK_H
#define ARDUINO_SERIAL_MOCK_H

#include <cstdint>
#include <cstddef>
#include <vector>

class SerialMock {
public:
    static void begin(unsigned long baud);
    static void end();
    static int available();
    static int read();
    static size_t write(uint8_t byte);
    static void print(const char* str);
    static void println(const char* str);
    static void flush();
    
    // For testing
    static void injectData(const uint8_t* data, size_t len);
    static std::vector<uint8_t> getWrittenData();
    static void clearWrittenData();
    
private:
    static std::vector<uint8_t> inputBuffer;
    static std::vector<uint8_t> outputBuffer;
    static size_t readIndex;
};

extern SerialMock Serial;

#endif // ARDUINO_SERIAL_MOCK_H