#include "DcsMock.h"
#include <iostream>
#include <cstring>

#include "../../../src/internal/PollingInput.h"
#include "../../../src/internal/ExportStreamListener.h"

namespace DcsBios {
    // Protocol.cpp.inc and ExportStreamListener.h both define these static members, but since we are not linking against the actual library, we need to define them here to avoid linker errors.
    // TODO refactor the library to avoid this kind of global state, which makes testing more difficult.
    ExportStreamListener* ExportStreamListener::firstExportStreamListener = nullptr;
    PollingInput* PollingInput::firstPollingInput = nullptr;
    
    static std::vector<std::pair<std::string, std::string>> messageLog;

    bool tryToSendDcsBiosMessage(const char* msg, const char* arg) {
        messageLog.emplace_back(msg ? msg : "", arg ? arg : "");
        return true;
    }

    void resetMessageLog() {
        messageLog.clear();
    }

    const std::vector<std::pair<std::string, std::string>>& getMessageLog() {
        return messageLog;
    }
}

// Global function for use by PollingInput and other code
bool tryToSendDcsBiosMessage(const char* msg, const char* arg) {
    return DcsBios::tryToSendDcsBiosMessage(msg, arg);
}
