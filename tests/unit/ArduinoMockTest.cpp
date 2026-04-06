#include <gtest/gtest.h>
#include "arduino/Arduino.h"

// Example: Test fixture for Protocol tests
class ArduinoMockTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset all mocks before each test
        ArduinoMock::reset();
    }

    void TearDown() override {
        ArduinoMock::reset();
    }
};


// Tests GPIO pin functionality: sets a pin to OUTPUT mode, writes HIGH, and verifies the value reads back correctly
TEST_F(ArduinoMockTest, PinModeAndWrite) {
    // Arrange & Act
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    
    // Assert
    EXPECT_EQ(digitalRead(13), HIGH);
}

// Tests the timing mock system: sets time to 0, delays 100ms, and verifies millis() returns 100
TEST_F(ArduinoMockTest, DelayAndMillis) {
    // Arrange
    TimeMock::setCurrentTime(0);
    
    // Act
    delay(100);
    unsigned long time1 = millis();
    
    // Assert
    EXPECT_EQ(time1, 100);
}

// Tests serial mock write functionality: writes three bytes and verifies they are correctly stored in the output buffer
TEST_F(ArduinoMockTest, SerialOutput) {
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


// Tests serial mock read functionality: injects test data, reads all bytes back, and verifies EOF returns -1
TEST_F(ArduinoMockTest, SerialDataRoundTrip) {
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

// Tests interrupt mock functionality: attaches/detaches interrupt handlers, triggers them, and verifies interrupt state control
TEST_F(ArduinoMockTest, InterruptsMock) {
    // Simple test handler function
    static int handlerCallCount = 0;
    auto testHandler = []() {
        handlerCallCount++;
    };
    
    handlerCallCount = 0;
    
    // Arrange: Attach interrupt handler to interrupt 0 with RISING mode
    attachInterrupt(0, testHandler, RISING);
    
    // Assert: Handler is stored correctly
    EXPECT_EQ(InterruptsMock::getMode(0), RISING);
    EXPECT_EQ(InterruptsMock::getHandler(0), testHandler);
    EXPECT_TRUE(InterruptsMock::areInterruptsEnabled());
    
    // Act: Trigger the interrupt
    InterruptsMock::triggerInterrupt(0);
    
    // Assert: Handler was called once
    EXPECT_EQ(handlerCallCount, 1);
    
    // Act: Trigger again
    InterruptsMock::triggerInterrupt(0);
    
    // Assert: Handler was called again
    EXPECT_EQ(handlerCallCount, 2);
    
    // Act: Disable interrupts and trigger
    noInterrupts();
    InterruptsMock::triggerInterrupt(0);
    
    // Assert: Handler was NOT called (interrupts disabled)
    EXPECT_EQ(handlerCallCount, 2);
    EXPECT_FALSE(InterruptsMock::areInterruptsEnabled());
    
    // Act: Re-enable interrupts and trigger
    interrupts();
    InterruptsMock::triggerInterrupt(0);
    
    // Assert: Handler was called again
    EXPECT_EQ(handlerCallCount, 3);
    
    // Act: Detach the interrupt
    detachInterrupt(0);
    InterruptsMock::triggerInterrupt(0);
    
    // Assert: Handler was NOT called after detach
    EXPECT_EQ(handlerCallCount, 3);
    EXPECT_EQ(InterruptsMock::getHandler(0), nullptr);
}

