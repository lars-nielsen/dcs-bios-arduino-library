#ifndef DCS_MOCK_H
#define DCS_MOCK_H

#include <string>
#include <vector>

#include "Arduino.h"
#include "internal/PollingInput.h"
#include "internal/ExportStreamListener.h"

// DCS-BIOS mock
namespace DcsBios {

    // Clutch 
    ExportStreamListener* ExportStreamListener::firstExportStreamListener = NULL;
	PollingInput* PollingInput::firstPollingInput = NULL;

    bool tryToSendDcsBiosMessage(const char* msg, const char* arg);

    void resetMessageLog();
    const std::vector<std::pair<std::string, std::string>>& getMessageLog();

    inline void assertMessageLogEmpty() {
        resetMessageLog();
    }
}

#endif // DCS_MOCK_H
