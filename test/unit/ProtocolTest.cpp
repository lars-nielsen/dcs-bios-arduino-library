#include <gtest/gtest.h>
#include "arduino/Arduino.h"

// Example: Test fixture for Protocol tests
class ProtocolTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset all mocks before each test
        ArduinoMock::reset();
        Serial.clearWrittenData();
    }

    void TearDown() override {
        ArduinoMock::reset();
    }
};

// Example test: Serial communication
TEST_F(ProtocolTest, SerialDataRoundTrip) {
    // Arrange
    uint8_t testData[] = {0x01, 0x02, 0x03, 0x04};
    
    // Act
    Serial.injectData(testData, sizeof(testData));
    EXPECT_EQ(Serial.available(), 4);
    
    uint8_t byte1 = Serial.read();
    uint8_t byte2 = Serial.read();
    uint8_t byte3 = Serial.read();
    uint8_t byte4 = Serial.read();
    int noMoreData = Serial.read();
    
    // Assert
    EXPECT_EQ(byte1, 0x01);
    EXPECT_EQ(byte2, 0x02);
    EXPECT_EQ(byte3, 0x03);
    EXPECT_EQ(byte4, 0x04);
    EXPECT_EQ(noMoreData, -1);
}

// Example test: GPIO functionality
TEST_F(ProtocolTest, PinModeAndWrite) {
    // Arrange & Act
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    
    // Assert
    EXPECT_EQ(digitalRead(13), HIGH);
}

// Example test: Timing
TEST_F(ProtocolTest, TimingMock) {
    // Arrange
    TimeMock::setCurrentTime(0);
    
    // Act
    delay(100);
    unsigned long time1 = millis();
    
    // Assert
    EXPECT_EQ(time1, 100);
}

// Example test: Serial output
TEST_F(ProtocolTest, SerialOutput) {
    // Arrange & Act
    Serial.write(0xAA);
    Serial.write(0xBB);
    Serial.write(0xCC);
    
    // Assert
    std::vector<uint8_t> output = Serial.getWrittenData();
    ASSERT_EQ(output.size(), 3);
    EXPECT_EQ(output[0], 0xAA);
    EXPECT_EQ(output[1], 0xBB);
    EXPECT_EQ(output[2], 0xCC);
}
