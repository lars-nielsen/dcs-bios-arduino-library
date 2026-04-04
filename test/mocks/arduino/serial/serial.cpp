#include "serial.h"

std::vector<uint8_t> SerialMock::inputBuffer;
std::vector<uint8_t> SerialMock::outputBuffer;
size_t SerialMock::readIndex = 0;

void SerialMock::begin(unsigned long baud) {
    // Mock implementation - just track that it was called
}

void SerialMock::end() {
    // Mock implementation
}

int SerialMock::available() {
    return inputBuffer.size() - readIndex;
}

int SerialMock::read() {
    if (readIndex < inputBuffer.size()) {
        return inputBuffer[readIndex++];
    }
    return -1;
}

size_t SerialMock::write(uint8_t byte) {
    outputBuffer.push_back(byte);
    return 1;
}

void SerialMock::print(const char* str) {
    while (*str) {
        write(*str++);
    }
}

void SerialMock::println(const char* str) {
    print(str);
    write('\n');
}

void SerialMock::flush() {
    // Mock implementation
}

void SerialMock::injectData(const uint8_t* data, size_t len) {
    inputBuffer.insert(inputBuffer.end(), data, data + len);
    readIndex = 0;
}

std::vector<uint8_t> SerialMock::getWrittenData() {
    return outputBuffer;
}

void SerialMock::clearWrittenData() {
    outputBuffer.clear();
}

SerialMock Serial;