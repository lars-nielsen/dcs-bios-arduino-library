#include <gtest/gtest.h>
#include "arduino/Arduino.h"

#include "../../src/internal/PollingInput.h"
#include "../../src/internal/Protocol.h"
#include "../../src/internal/Buttons.h"
#include "../../test/mocks/dcs/DcsMock.h"

// Test fixture for Button tests
class ButtonsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset all mocks before each test
        ArduinoMock::reset();
        Serial.clearWrittenData();
        DcsBios::resetMessageLog();
    }

    void TearDown() override {
        ArduinoMock::reset();
    }
};

TEST_F(ButtonsTest, ActionButton_SendsMessageOnButtonPress) {
    // Arrange
    char testPin = 5;
    digitalWrite(testPin, HIGH); // Set initial pin state to HIGH (button not pressed)

    DcsBios::ActionButton button("TEST_BUTTON", "1", testPin);

    // Act: Simulate button press (HIGH to LOW transition)
    digitalWrite(testPin, LOW);
    TimeMock::advanceTime(1); // Advance time to trigger polling
    DcsBios::PollingInput::pollInputs(); // This should trigger the message send

    // Assert
    auto messages = DcsBios::getMessageLog();
    ASSERT_EQ(messages.size(), 1);
    EXPECT_EQ(messages[0].first, "TEST_BUTTON");
    EXPECT_EQ(messages[0].second, "1");
}